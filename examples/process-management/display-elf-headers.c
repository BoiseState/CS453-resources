
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <linux/elf.h>
#include <stdio.h>

/*
 *
 *from /usr/include/linux/elf.h
 *
#define EI_NIDENT	16

typedef struct elf64_hdr{
  unsigned char	e_ident[EI_NIDENT];
  Elf64_Half	e_type;
  Elf64_Half	e_machine;
  Elf64_Word	e_version;
  Elf64_Addr	e_entry;  
  Elf64_Off	e_phoff;
  Elf64_Off	e_shoff;
  Elf64_Word	e_flags;
  Elf64_Half	e_ehsize;
  Elf64_Half	e_phentsize;
  Elf64_Half	e_phnum;
  Elf64_Half	e_shentsize;
  Elf64_Half	e_shnum;
  Elf64_Half	e_shstrndx;
} Elf64_Ehdr;

#define PT_NULL    0
#define PT_LOAD    1
#define PT_DYNAMIC 2
#define PT_INTERP  3
#define PT_NOTE    4
#define PT_SHLIB   5
#define PT_PHDR    6
#define PT_LOPROC  0x70000000
#define PT_HIPROC  0x7fffffff
#define PT_MIPS_REGINFO		0x70000000


These constants define the permissions on sections in the program
header, p_flags. 

#define PF_R		0x4
#define PF_W		0x2
#define PF_X		0x1

*/

#define MAXLEN 50

char *decipher_flags(Elf64_Word flags)
{
	unsigned int pf_x = (flags & 0x1);
	unsigned int pf_w = (flags & 0x2);
	unsigned int pf_r = (flags & 0x4);
	char * message = (char *)malloc(sizeof(char)*MAXLEN);

	strcpy(message," ");
	if (pf_x)  strcat(message,"PF_X ");
	if (pf_w)  strcat(message,"PF_W ");
	if (pf_r)  strcat(message,"PF_R ");
	return message;
}


char *decipher_type(Elf64_Word type)
{
		char * message = (char *)malloc(sizeof(char)*MAXLEN);
		switch (type)
		{
			case 0: strcpy(message, "PT_NULL");break;
			case 1: strcpy(message, "PT_LOAD");break;
			case 2: strcpy(message, "PT_DYNAMIC");break;
			case 3: strcpy(message, "PT_INTERP");break;
			case 4: strcpy(message, "PT_NOTE");break;
			case 5: strcpy(message, "PT_SHLIB");break;
			case 6: strcpy(message, "PT_PHDR");break;
			default: strcpy(message, "unknown");break;
		}
		return message;
}

int main(int argc, char **argv)
{
	int fd;
	int i;
	struct elf64_hdr header;
	struct elf64_phdr phdr;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <executable file>\n",argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror(argv[0]);
		exit(1);
	}
	read(fd, &header, sizeof(struct elf64_hdr));

	printf("e_ident = %s \n",header.e_ident);
	printf("e_entry = 0x%llx \n",header.e_entry);
	printf("e_phoff = %lld \n",header.e_phoff);
	printf("e_phentsize = %d \n",header.e_phentsize);
	printf("e_phnum = %d \n",header.e_phnum);


	for (i=0; i<header.e_phnum; i++)
	{
		read(fd, &phdr, sizeof(struct elf64_phdr));
		printf("--------physical header------- \n");
		printf("p_type =  %s \n",decipher_type(phdr.p_type));
		printf("p_offset = %lld \n",phdr.p_offset);
		printf("p_vaddr = 0x%llx \n",phdr.p_vaddr);
		printf("p_filesz = %lld \n",phdr.p_filesz);
		printf("p_memsz = %lld \n",phdr.p_memsz);
		printf("p_flags = %s \n", decipher_flags(phdr.p_flags));
		printf("\n");
	}
	exit(0);
}
