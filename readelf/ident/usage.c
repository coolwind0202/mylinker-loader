#include <stdio.h>

void print_usage(FILE *fp, char *program_name)
{
  fprintf(fp, "Usage: %s <option(s)> elf-file(s)\n", program_name);
  fputs(" Display information about the contents of ELF format files\n", fp);
  fputs(" Options are:\n", fp);
  fputs("  -a --all               Equivalent to: -h -l -S -s -r -d -V -A -I\n", fp);
  fputs("  -h --file-header       Display the ELF file header\n", fp);
}