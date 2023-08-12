#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <elf.h>
#include <stdio.h>
#include <sys/stat.h>

void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
void check_elf(unsigned char *e_ident);


/**
 * ELF-Check - This check if file is ELF or not.
 * @e_ident:This points to an array encompassing the ELF magic numbers.
 * Description: If the file is not an ELF file, or on error, exit with status code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file.\n");
			exit(98);
		}
	}
}

/**
 * print_magic: This is used to prints the magic number of an ELF header.
 * @e_ident: This points to an array encompassing the ELF magic numbers.
 * Description: Spaces are used to separate magic numbers.
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class: This is used to print the class of an ELF header.
 * @e_ident: This points to an array encompassing the ELF magic numbers.
 * Description: This is employed to determine the architecture mode
 * in which the code operates, whether on a 32-bit or 64-bit system.
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none.\n");
		break;
	case ELFCLASS32:
		printf("ELF32.\n");
		break;
	case ELFCLASS64:
		printf("ELF64.\n");
		break;
	default:
		printf("<unknown:: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Printing the data of an ELF header is done with this.
 * @e_ident: This pointer points to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none.\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian.\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian.\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/*
 * print_version - Used in printing the version of an ELF header.
 * @e_ident: This pointer points to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/*
 * print_osabi - Displays the Operating System/ABI specified in an ELF header.
 * @e_ident: An indicator to an array encompassing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
???LINES MISSING
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(a);
	return (0);
}

