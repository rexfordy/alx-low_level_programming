#include <elf.h>
#include "main.h"
#define REV(n) ((n << 24) | (((n >> 16) << 24) >> 16) | \
(((n << 16) >> 24) << 16) | (n >> 24))
/**
 * verify- verify the textfile to check if is a ELF
 * @elf_ident: the ELF struct
 * return: no return is a void function.
 */
void verify(unsigned char *elf_ident)
{
	if (*(elf_ident) == 0x7f && *(elf_ident + 1) == 'E' &&
	    *(elf_ident + 2) == 'L' && *(elf_ident + 3) == 'F')
	{
		printf("ELF Header:\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error Message: This is NOT a valid ELF\n");
		exit(98);
	}
}

/**
 * magic - This print magic number
 * @elf_ident: the ELF struct.
 * return: no return is a void funcion.
 */
void magic(unsigned char *elf_ident)
{
	int n; /* the index to count the magic bytes */
	int ltd;

	ltd = EI_NIDENT - 1;
	printf("  Magic:   ");
	for (n = 0; n < ltd; n++)
		printf("%02x ", *(elf_ident + n));
	printf("%02x\n", *(elf_ident + n));
}
/**
 * class - print the class of the selected ELF
 * @elf_ident: the ELF struct on working
 * return: no return is a void func.
 */
void class(unsigned char *elf_ident)
{
	printf("  Class:                             ");
	if (elf_ident[EI_CLASS] == ELFCLASSNONE)
		printf("This class is invalid\n");
	else if (elf_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (elf_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
}
/**
 * info - Print the type of data in the struc.
 * @elf_ident: This is the ELF struct
 * return: no return is a void function.
 */
void info(unsigned char *elf_ident)
{
	printf("  Data:                              ");
	if (elf_ident[EI_DATA] == ELFDATANONE)
		printf("This is an unknown data format\n");
	else if (elf_ident[EI_DATA] == ELFDATA2LSB)
		printf("This is a 2's complement, little endian\n");
	else if (elf_ident[EI_DATA] == ELFDATA2MSB)
		printf(" This is a 2's complement, big endian\n");
	else
		printf("<This is unknown: %x>\n", elf_ident[EI_DATA]);
}
/**
 * version - print the version of the file
 * @elf_ident: the ELF struct
 * return: no return is a void func.
 */
void version(unsigned char *elf_ident)
{
	printf("  Version:                           ");
	if (elf_ident[EI_VERSION] == EV_CURRENT)
		printf("%i (current)\n", EV_CURRENT);
	else
		printf("%i\n", elf_ident[EI_VERSION]);
}

/**
 * osabi - print the osabi
 * @elf_ident: the ELF struct
 * return: no return is a void func.
 */
void osabi(unsigned char *elf_ident)
{
	printf("  OS/ABI:                            ");
	if (elf_ident[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", elf_ident[EI_OSABI]);
}

/**
 * type - print the type
 * @elf_ident: the ELF struct
 * @e_type: data to compare and print.
 * return: no return is a void func.
 */
void type(unsigned int e_type, unsigned char *elf_ident)
{
	elf_ident[EI_DATA] == ELFDATA2MSB ? e_type = e_type >> 8 : e_type;

	printf("  Type:                              ");
	if (e_type == ET_NONE)
		printf("NONE (Unknown type)\n");
	else if (e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", e_type);
}

/**
 * entry - print the entry point
 * @elf_ident: the ELF struct
 * @e_entry: the data to print
 * return: no return is a void func.
 */
void entry(unsigned int e_entry, unsigned char *elf_ident)
{
	if (elf_ident[EI_DATA] == ELFDATA2MSB)
		e_entry = REV(e_entry);

	printf("  Entry point address:               ");
	printf("%#x\n", (unsigned int)e_entry);
}

/**
 * main - read a ELF file.
 * @argc: the number of args
 * @argv: the Args
 * section header: the header of this function is main.h
 * Return: 0 in success
 */
int main(int argc, char *argv[])
{
	int fd, read_new, close_new;
	Elf64_Ehdr *file;

	if (argc > 2 || argc < 2)
		dprintf(STDERR_FILENO, "Use: error in # of args\n"), exit(98);
	file = malloc(sizeof(Elf64_Ehdr));
	if (file == NULL)
		dprintf(STDERR_FILENO, "Error in allocate memory\n"), exit(98);
	fd = open(*(argv + 1), O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error Message: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	read_new = read(fd, file, sizeof(Elf64_Ehdr));
	if (read_new == -1)
	{
		free(file);
		dprintf(STDERR_FILENO, "Error Message: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	verify(file->elf_ident);
	magic(file->elf_ident);
	class(file->elf_ident);
	info(file->elf_ident);
	version(file->elf_ident);
	osabi(file->elf_ident);
	printf("  ABI Version:                       ");
	printf("%i\n", file->elf_ident[EI_ABIVERSION]);
	type(file->e_type, file->elf_ident);
	entry(file->e_entry, file->elf_ident);
	free(file);
	close_new = close(fd);
	if (close_new)
	{
		dprintf(STDERR_FILENO, "Error Message: Can't close fd\n");
		exit(98);
	}
	return (0);
}
