#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "pkg.h"

#define TITLE "pkgtool"
#define VERSION "v0.1"

void
print_help()
{
  printf("\n");

  printf( "Usage:\n"
        "  Format:\n"
        "    pkg_tool [options] <input>\n"
        "  Description :\n"
        "    Analyze and extract contents of pkg files.\n"
        "  Options:\n"
        "    -e, --extract                   Extract data from pkg.\n"
        "      -o, --output <outdir>         Set extraction drectory.\n"
        "    -s, --sig                       Print extracted signature from pkg.\n"
        "    -p, --param                     Print PARAM.SFO information from pkg.\n"
        "    -l, --list                      List contents of pkg.\n"
        "    -v, --version                   Print program version.\n"
        "    -h, --help (DEFAULT)            Print this help text.\n"
        "  Arguments:\n"
        "    <input>                         Path of pkg file.\n"
  );
  
  printf("\n");
}

void
print_version()
{
  printf("%s %s\n", TITLE, VERSION);
}

int
main (int argc, char *argv[])
{
  if (argc < 2) {
    print_help();
    return 0;
  }
    
  if( argc < 6 && !strcmp(argv[1], "-e") || !strcmp(argv[1], "--extract") ) {
    if ( argc == 5 && (!strcmp(argv[2], "-o") || !strcmp(argv[2], "--output")) ) {
      pkg_unpack (argv[4], argv[3]);
    } else
    if (argc == 3) {
      pkg_unpack (argv[2], NULL);
    } else {
      printf("Invalid number of arguments, see --help for more information.\n");
    }
    return 0;
  }
  
  if (argc > 3) {
    printf("Invalid number of arguments, see --help for more information.\n");
    return 0;
  }
  
  if (argc == 2) {
    if( !strcmp(argv[1], "-v") || !strcmp(argv[1], "--version") ) {
      print_version();
    } else
    if ( !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help") ) {
      print_help();
    } else {
      printf("Invalid arguments used, see --help for more information.\n");
    }
    return 0;
  }
  
  if( !strcmp(argv[1], "-s") || !strcmp(argv[1], "--sig") ) {
    pkg_extract_sig (argv[2]);
  } else
  if( !strcmp(argv[1], "-p") || !strcmp(argv[1], "--params") ) {
    pkg_print_params (argv[2]);
  } else
  if( !strcmp(argv[1], "-l") || !strcmp(argv[1], "--list") ) {
    pkg_list (argv[2]);
  } else {
    printf("Invalid arguments used, see --help for more information.\n");
  }
  return 0;
}
