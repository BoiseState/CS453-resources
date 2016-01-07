#include <stdio.h>
#include "simple-malloc.h"

static Header base;
static Header *free_list_head = NULL;

static void format_memory_and_add_to_free_list(void* raw_memory, int number_of_units);
static int reached_end_of_free_list(Header* current_block);
static void* get_memory_location_from_block(Header* current_block);
static Header* allocate_block(Header* current_block, int number_of_units_to_allocate);
static int current_block_is_large_enough(int current_block_size, int number_of_units);
static int bytes_to_number_of_units(int);
static void initialize_list(Header* previous_block);
static Header* find_available_insertion_point(Header* memory_to_free);
static int should_combine_with_upper_neighbour(Header* block_to_free, Header* insertion_block);
static void combine_with_upper_neighbour(Header* block_to_free, Header* insertion_point);
static int should_combine_with_lower_neighbour(Header* block_to_free, Header* insertion_point);
static void combine_with_lower_neighbour(Header* block_to_free, Header* insertion_point);
static Header *get_more_memory_from_os(unsigned);


void* simple_malloc(unsigned number_of_bytes_requested)
{
	Header *current_block = NULL, *last_seen_free_block = NULL;
	unsigned number_of_units_to_allocate;
	
	number_of_units_to_allocate = bytes_to_number_of_units(number_of_bytes_requested);
    if (free_list_head == NULL)
    {
        initialize_list(last_seen_free_block);
    }
    last_seen_free_block = free_list_head;

	for (current_block = last_seen_free_block->metadata.next_free_block; ; last_seen_free_block = current_block, current_block = current_block->metadata.next_free_block)
    {
		if (current_block_is_large_enough(current_block->metadata.size, number_of_units_to_allocate))
        {
            if (current_block->metadata.size == number_of_units_to_allocate)
            {
                last_seen_free_block->metadata.next_free_block = current_block->metadata.next_free_block;
            }
            else
            {
                current_block = allocate_block(current_block, number_of_units_to_allocate);
			}
            free_list_head = last_seen_free_block;
			return get_memory_location_from_block(current_block);
		}
		if (reached_end_of_free_list(current_block))
        {
            Header* obtained_memory = get_more_memory_from_os(number_of_units_to_allocate);
            if (obtained_memory == NULL)
            {
                return NO_MEMORY_LEFT;
            }
            else
            {
                current_block = obtained_memory;
            }
        }
	}
}

static Header* get_more_memory_from_os(unsigned number_of_units)
{
	void* raw_memory;

	if (number_of_units < MINIMUM_NUMBER_OF_UNITS)
    {
        number_of_units = MINIMUM_NUMBER_OF_UNITS;
    }
		
	raw_memory = sbrk(number_of_units * sizeof(Header));
    
	if (raw_memory == (void *) -1)
    {
        return NO_MEMORY_LEFT;
    }
    
    format_memory_and_add_to_free_list(raw_memory, number_of_units);
    
	return free_list_head;
}

void simple_free(void *used_memory_address)
{
    Header* block_to_free = (Header *) used_memory_address - 1;;

    Header* insertion_point = find_available_insertion_point(block_to_free);
	
	if (should_combine_with_upper_neighbour(block_to_free, insertion_point))
    {
        combine_with_upper_neighbour(block_to_free, insertion_point);
	}
    else
    {
        block_to_free->metadata.next_free_block = insertion_point->metadata.next_free_block;
    }
			
	if (should_combine_with_lower_neighbour(block_to_free, insertion_point))
    {
        combine_with_lower_neighbour(block_to_free, insertion_point);
    }
    else
    {
        insertion_point->metadata.next_free_block = block_to_free;
    }
			
	free_list_head = insertion_point;
}


/**
 * print out the free list for demonstration purposes 
 */
void print_free_list()
{
	Header *next;
	int i;

	if (!free_list_head) {
		printf("free list is empty\n");
		return;
	}
	i=0; 
	printf("\n");
	next = free_list_head;
	do {
		printf("node %d: size = %u bytes\n", i, next->metadata.size * (unsigned) sizeof(Header));
    	next = next->metadata.next_free_block;;
		i++;
	} while (next != free_list_head); 
	printf("\n");
}

static int bytes_to_number_of_units(int number_of_bytes_requested)
{
    return (number_of_bytes_requested+sizeof(Header)-1)/sizeof(Header) + 1;
}

static void initialize_list(Header* previous_block)
{
    base.metadata.next_free_block = free_list_head = previous_block = &base;
    base.metadata.size = 0;
}

static int current_block_is_large_enough(int current_block_size, int number_of_units)
{
    return current_block_size >= number_of_units;
}

static Header* allocate_block(Header* current_block, int number_of_units_to_allocate)
{
    current_block->metadata.size -= number_of_units_to_allocate;
    current_block += current_block->metadata.size;
    current_block->metadata.size = number_of_units_to_allocate;
    return current_block;
}

static void* get_memory_location_from_block(Header* current_block)
{
    return (void *) (current_block+1);
}

static int reached_end_of_free_list(Header* current_block)
{
    return current_block == free_list_head;
}

static void format_memory_and_add_to_free_list(void* raw_memory, int number_of_units)
{
    Header* block_formatted_memory = (Header *) raw_memory;
    block_formatted_memory->metadata.size = number_of_units;
    simple_free(get_memory_location_from_block(block_formatted_memory));
}

static Header* find_available_insertion_point(Header* memory_to_free)
{
    Header* current_block;
    for (current_block = free_list_head;!(memory_to_free > current_block && memory_to_free < current_block->metadata.next_free_block); current_block = current_block->metadata.next_free_block)
    {
        if (current_block >= current_block->metadata.next_free_block && (memory_to_free > current_block || memory_to_free < current_block->metadata.next_free_block))
        {
            break;
        }
    }
    return current_block;
}

static int should_combine_with_upper_neighbour(Header* block_to_free, Header* insertion_block)
{
    return block_to_free + block_to_free->metadata.size == insertion_block->metadata.next_free_block;
}

static void combine_with_upper_neighbour(Header* block_to_free, Header* insertion_point)
{
    block_to_free->metadata.size += insertion_point->metadata.next_free_block->metadata.size;
    block_to_free->metadata.next_free_block = insertion_point->metadata.next_free_block->metadata.next_free_block;
}

static int should_combine_with_lower_neighbour(Header* block_to_free, Header* insertion_point)
{
    return insertion_point + insertion_point->metadata.size == block_to_free;
}

static void combine_with_lower_neighbour(Header* block_to_free, Header* insertion_point)
{
    insertion_point->metadata.size += block_to_free->metadata.size;
    insertion_point->metadata.next_free_block = block_to_free->metadata.next_free_block;
}
/* vim: set ts=4: */
