#include <elf.h>
#include "main.h"
#define REV(n) ((n << 24) | (((n >> 16) << 24) >> 16) | \
(((n << 16) >> 24) << 16) | (n >> 24))
/**
 * verify- verify the file to check if is a ELF
 * @el_ident: the ELF struct
 * return: no return is a void func.
 */
void verify(unsigned char *el_ident)
{
	if (*(el_ident) == 0x7f && *(el_ident + 1) == 'E' &&
	    *(el_ident + 2) == 'L' && *(el_ident + 3) == 'F')
	{
		printf("ELF Header:\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: this file not is a valid ELF\n");
		exit(98);
	}
}

/**
 * magic - print magic number
 * @el_ident: the ELF struct
 * return: no return is a void func.
 */
void magic(unsigned char *el_ident)
{
	int ind_magic; /* the index to count the magic bytes */
	int lmt;

	lmt = EI_NIDENT - 1;
	printf("  Magic:   ");
	for (ind_magic = 0; ind_magic < lmt; ind_magic++)
		printf("%02x ", *(el_ident + ind_magic));
	printf("%02x\n", *(el_ident + ind_magic));
}
/**
 * class - print the class of the ELF
 * @el_ident: the ELF struct in the function
 * return: no return is a void function.
 */
void class(unsigned char *el_ident)
{
	printf("  Class:                             ");
	if (el_ident[EI_CLASS] == ELFCLASSNONE)
		printf("This class is invalid\n");
	else if (el_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (el_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", el_ident[EI_CLASS]);
}
/**
 * data - print the type of data
 * @el_ident: the ELF struct in the function
 * return: no return is a void function.
 */
void data(unsigned char *el_ident)
{
	printf("  Data:                              ");
	if (el_ident[EI_DATA] == ELFDATANONE)
		printf("Unknown data format\n");
	else if (el_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (el_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", el_ident[EI_DATA]);
}
/**
 * version - print the version of the textfile
 * @el_ident: the ELF struct in the function
 * return: no return is a void function.
 */
void version(unsigned char *el_ident)
{
	printf("  Version:                           ");
	if (el_ident[EI_VERSION] == EV_CURRENT)
		printf("%i (current)\n", EV_CURRENT);
	else
		printf("%i\n", el_ident[EI_VERSION]);
}

/**
 * osabi - print the osabi
 * @el_ident: the ELF struct in the function
 * return: no return is a void function.
 */
void osabi(unsigned char *el_ident)
{
	printf("  OS/ABI:                            ");
	if (el_ident[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (el_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (el_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (el_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (el_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (el_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (el_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (el_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (el_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (el_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", el_ident[EI_OSABI]);
}

/**
 * type - print the type
 * @el_ident: the ELF struct in the function
 * @el_typ: data to compare and print out.
 * return: no return is a void function.
 */
void type(unsigned int el_typ, unsigned char *el_ident)
{
	el_ident[EI_DATA] == ELFDATA2MSB ? el_typ = el_typ >> 8 : el_typ;

	printf("  Type:                              ");
	if (el_typ == ET_NONE)
		printf("NONE (Unknown type)\n");
	else if (el_typ == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (el_typ == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (el_typ == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (el_typ == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", el_typ);
}

/**
 * entry - print the entry point in the func
 * @el_ident: the ELF struct in the func.
 * @el_ent: the data to print out
 * return: no return is a void function.
 */
void entry(unsigned int el_ent, unsigned char *el_ident)
{
	if (el_ident[EI_DATA] == ELFDATA2MSB)
		el_ent = REV(el_ent);

	printf("  Entry point address:               ");
	printf("%#x\n", (unsigned int)el_ent);
}

/**
 * main - read a ELF file required.
 * @argc: the number of args in the file
 * @argv: the Args
 * section header: the header is main.h
 * Return: 0 in success
 */
int main(int argc, char *argv[])
{
	int fot, _read, _close;
	Elf64_Ehdr *file;

	if (argc > 2 || argc < 2)
		dprintf(STDERR_FILENO, "Usage: error in # of args\n"), exit(98);
	file = malloc(sizeof(Elf64_Ehdr));
	if (file == NULL)
		dprintf(STDERR_FILENO, "error in allocate memory\n"), exit(98);
	fot = open(*(argv + 1), O_RDONLY);
	if (fot == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	_read = read(fot, file, sizeof(Elf64_Ehdr));
	if (_read == -1)
	{
		free(file);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	verify(file->el_ident);
	magic(file->el_ident);
	class(file->el_ident);
	data(file->el_ident);
	version(file->el_ident);
	osabi(file->el_ident);
	printf("  ABI Version:                       ");
	printf("%i\n", file->el_ident[EI_ABIVERSION]);
	type(file->el_typ, file->el_ident);
	entry(file->el_ent, file->el_ident);
	free(file);
	_close = close(fot);
	if (_close)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fot\n");
		exit(98);
	}
	return (0);
}
