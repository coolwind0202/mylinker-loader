#include <stdio.h>
#include <elf.h>

#define IDENT_CLASS 4
#define IDENT_DATA 5
#define IDENT_VERSION 6
#define IDENT_OSABI 7
#define IDENT_ABI_VERSION 8

typedef struct
{
  unsigned char class;
  unsigned char data;
  unsigned char version;
  unsigned char osabi;
  unsigned char abi_version;
} ELF_IDENT;

void read_file_header(FILE *fp, ELF_IDENT *ans, unsigned char *magic)
{
  unsigned char buf[16];
  fseek(fp, 0, SEEK_SET);
  fread(buf, 16, 1, fp);

  magic = buf;

  ans->class = buf[IDENT_CLASS];
  ans->data = buf[IDENT_DATA];
  ans->version = buf[IDENT_VERSION];
  ans->osabi = buf[IDENT_OSABI];
  ans->abi_version = buf[IDENT_ABI_VERSION];
}

void unsigned_char_to_hex(unsigned char c, char *ans)
{
}

void magic_to_hex(unsigned char *magic, char *ans)
{
}

void print_file_header(FILE *fd, ELF_IDENT *elf, unsigned char *magic)
{
  char magicHex[2 * 16 + 15];
  magic_to_hex(magic, magicHex);
  fputs("ELF Header:\n", fd);
  fprintf(fd, "  Magic:   %s\n", magicHex);
  fprintf(fd, "Class:                             %s\n", "WIP");
  fprintf(fd, "read:                              %s\n", "WIP");
  fprintf(fd, "Version:                           %d (current)\n", (int)elf->version);
  fprintf(fd, "OS/ABI:                            %s\n", "WIP");
  fprintf(fd, "ABI Version:                       %d\n", (int)elf->abi_version);
}