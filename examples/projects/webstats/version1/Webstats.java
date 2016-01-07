/*
Original Author: Jeff Cope
Maintaining Author: Amit Jain
Class: CS 453


*/

import java.io.*;
import java.util.StringTokenizer;

public class Webstats
{
	private final int MAX_LINE_SIZE = 4096;
	private final int MAX_NUM_FIELDS = 40;
	
	private double local_bytes;
	private double total_bytes;
	private double local_gets;
	private double total_gets;
	private double failed_gets;
	private double local_failed_gets;
	private String url;
	private int requests;

	private String program_name;
	
	/**
	  parse_line(): Parse one line into String tokens separated by the given delimiters.
	  @param line A character array containing the current server log entry line
	  @param delim: A character array containing the delimiters to be used to separate fields in the line
	  @return The number of tokens found in the line.
	*/
	private int parse_line(String line, String delim, String field[])
	{
		String next;
		int cnt = 0;
		StringTokenizer strtok = new StringTokenizer(line, delim);
		while (strtok.hasMoreTokens())
		{
			next = strtok.nextToken();
			if (cnt == MAX_NUM_FIELDS-1) break;
			field[cnt++] = next;
		}
		field[cnt] = null; /* make the field array be null-terminated */
		return cnt;
	}

	/*
	   free_tokens(): Clears spaces allocated for tokens in parse_line
	   @param num An int representing number of tokens in array of strings named field.
	   @param field An array of Strings
	   @return none.
	*/
	private void free_tokens(int num, String field[])
	{
		for (int i = 0; i < num; i++)
		{
			field[i] = "";
		}
	}
	
	/**
	  Webstats(): Initializes the webstats structure.
	  @param new_program_name This programs name.
	  @return none
	*/
	public Webstats(String new_program_name)
	{
		program_name = new_program_name;
		local_bytes = 0;
		total_bytes = 0;
		local_gets = 0;
		total_gets = 0;
		failed_gets = 0;
		local_failed_gets = 0;
	}

	private final int HTTP_STATUS_CODE_FIELD = 8;
	private final int BYTES_DOWNLOADED_FIELD = 9;

	/*
	  update_webstats(): Updates the webstats structure based on the input fields of current line.
	  @param num The number of fields in the current webserver log entry
	  @param field An array of num Strings representing the log entry
	  @return none
	*/
	private void update_webstats(int num, String field[])
	{
		int bytes_downloaded = 0;
		try {
			bytes_downloaded = Integer.parseInt(field[BYTES_DOWNLOADED_FIELD]);
		} catch (NumberFormatException e) {
			//skip lines without downloaded bytes field
		}
		total_gets++;
		total_bytes += bytes_downloaded;
		if (field[HTTP_STATUS_CODE_FIELD].equals("404"))
			failed_gets++;

		if ((field[0].indexOf("boisestate.edu") != -1) || (field[0].indexOf("132.178") != -1)) {
			local_gets++;
			local_bytes += bytes_downloaded;
			if (field[HTTP_STATUS_CODE_FIELD].equals("404"))
				local_failed_gets++;
		}
	}

	/*
	  print_webstats(): Print out webstats on standard output.
	  @return none
	*/
	private void print_webstats()
	{
		System.out.printf("%10s %15s   %15s  %15s\n", "TYPE", "gets","failed gets", "MB transferred");

		System.out.printf("%10s  %15.0f  %15.0f  %15.0f\n", "local", local_gets, local_failed_gets, 
													(double) local_bytes/(1024*1024));
		System.out.printf("%10s  %15.0f  %15.0f  %15.0f\n", "total", total_gets, failed_gets, 
													(double) total_bytes/(1024*1024));

	}
	
	/**
	  process_file(): The main function that processes one log file
	  @param ptr Pointer to log file name.
	  @return none
	  output: none
 	*/
	public void process_file(Object ptr)
	{
		String filename = (String) ptr;
		String linebuffer;
		String field[] = new String[MAX_NUM_FIELDS]; 
		String end_date = "";

		System.err.println(program_name + ": processing log file " + filename);
		try {
			BufferedReader fin = new BufferedReader(new FileReader(new File(filename)));
			try {
				linebuffer = fin.readLine();
				if (linebuffer != null) {
					int num = parse_line(linebuffer, " []\"", field);
					update_webstats(num, field);
					System.out.println("Starting date: " + field[3]);
					free_tokens(num, field);
					
					while ((linebuffer = fin.readLine()) != null) {
						num = parse_line(linebuffer, " []\"", field);
						end_date = field[3];
						update_webstats(num, field);
						free_tokens(num, field);
						linebuffer = "";
					}
					System.out.println("Ending date: "+ end_date);
				}
			} catch (IOException e) {
				System.err.println("Cannot read from file "+ filename);
				System.exit(1);
			}
		} catch (FileNotFoundException e) {
			System.err.println("Cannot open file "+ filename);
			System.exit(1);
		}
	}


	public static void main(String argv[])
	{
		if (argv.length < 1)
		{
			System.err.println("Usage: java Webstats <access_log_file> {<access_log_file>}");
			System.exit(1);
		}
		
		Webstats ws = new Webstats("Webstats.java");
		
		for (int i = 0; i < argv.length; i++)
		{
			/*process the ith file*/
			ws.process_file(argv[i]);
		}
		
		ws.print_webstats();
		System.exit(0);
	}
}

/* vim: set ts=4: */
