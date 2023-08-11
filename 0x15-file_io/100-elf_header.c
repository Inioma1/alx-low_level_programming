#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <elf.h>


void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

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
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
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
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
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
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
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

/**
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
			case ELFOSABI_LINUX:
				printf("UNIX - Linux\n");
				break;
			case ELFOSABI_SOLARIS:
				printf("UNIX - Solaris\n");
				break;
			case ELFOSABI_IRIX:
				printf("UNIX - IRIX\n");
				break;
			case ELFOSABI_FREEBSD:
				printf("UNIX - FreeBSD\n");
				break;
			case ELFOSABI_TRU64:
				printf("UNIX - TRU64\n");
				break;
			case ELFOSABI_ARM:
				printf("ARM\n");
				break;
			case ELFOSABI_STANDALONE:
				printf("Standalone App\n");
				break;
			default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
		}
}

/**
 * print_abi - Displays the ABI version specified in an ELF header.
 * @e_ident: An indicator to an array encompassing the ELF version.
 * Description: this is used to print the version of the ELF.
 */

void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Display the type of an ELF header.
 * @e_type: An ELF type.
 * @e_ident: A pointer to an array encompassing the ELF class.
 * Description: Used to print the type file.
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
		printf(" Type: ");
	switch (e_type)
	i{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Displays the starting point address indicated in an ELF header.
 * @e_entry: The memory location of the ELF entry point.
 * @e_ident: An indicator to an array encompassing the ELF class.
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - This closes an ELF file.
 * @elf: The file handle of the ELF file.
 *
 * Description: In the event of inability to close the file, exit with code 98.
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
/*
 * main - This presents the data within the ELF header 
 * from the beginning of an ELF file.
 * @argc: The number of arguments in the program.
 * @argv: An array to an argument.
 * Return: 0 if Success.
 */

int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	if (argc != 2)
       	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	o = open(argv[1], O_RDONLY);
	if (o == -1)
       	{
		perror("Error opening file");
		return (1);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL) 
	{
		perror("Error allocating memory");
		close(o);
		return (1);
	}

	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
       	{
		perror("Error reading file");
		free(header);
		close(o);
		return (1);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close(o);
	return (o);
}
