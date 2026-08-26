/**
  @file chessboard.c
  This program decodes a chessboard description in a compressed representation and
  draws a picture of the chessboard as output.
*/

#include <stdio.h>
#include <wchar.h> // For wide characters.
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/** Width and height of the chessboard. */
#define SIZE 8

/** Piece type value for a pawn. */
#define PAWN 1

/** Piece type value for a knight (shown as N) */
#define NGHT 2

/** Piece type value for a bishop */
#define BSHP 3

/** Piece type value for a rook */
#define ROOK 4

/** Piece type value for a queen */
#define QUEN 5

/** Piece type value for a king */
#define KING 6

/**
   Decode a piece from the given input value and fill in the appropriate board
   position.
   @param input Binary encoding of the piece type and location.
   @param board Representation of the chessboard.
*/
void decodePiece( unsigned short input, char board[ SIZE ][ SIZE ] )
{
  // ...
}

/**
  Print the chessboard as ASCII text format. 
  @param board Representation of the chessboard.
*/
void printText( char board[ SIZE ][ SIZE ] )
{
  // ...
}

/**
   This funciton is just for fun.  It prints the chessboard using unicode
   characters for the chess pieces, rather than letters.  This function has to do
   some things you shouldn't do, if you just need to print the board as ACII text.
   @param board Representation of the chessboard.
*/
void printGraphical( char board[ SIZE ][ SIZE ])
{
  // For each character on the board, c, charMap[ c ] is a wide character
  // (unicode symbol) to print c so it looks like a chess piece.
  static const int charMap[ ] = {
    [ 0 ] = '-',      // empty space
    [ 'P' ] = 0x2659, // Light pawn
    [ 'p' ] = 0x265F, // Dark pawn
    [ 'N' ] = 0x2658, // Light knight
    [ 'n' ] = 0x265E, // Dark knight
    [ 'B' ] = 0x2657, // Light bishop
    [ 'b' ] = 0x265D, // Dark bishop
    [ 'R' ] = 0x2656, // Light rook
    [ 'r' ] = 0x265C, // Dark rook
    [ 'Q' ] = 0x2655, // Light queen
    [ 'q' ] = 0x265B, // Dark queen
    [ 'K' ] = 0x2654, // Light king
    [ 'k' ] = 0x265A  // Dark king
  };
  
  setlocale( LC_CTYPE, "" );
  for ( int r = 0; r < SIZE; r++ ) {
    for ( int c = 0; c < SIZE; c++ ) {
      // Blanks bttween the pieces.
      if ( c > 0 )
        wprintf( L" " );
      wprintf( L"%lc", charMap[ (int) board[ r ][ c ] ] );
    }
    wprintf( L"\n" );
  }
}

/** Minimum number of commad-line paramters required. */
#define MIN_ARGS 2

int main(int argc, char *argv[])
{
  // Look for a -g flag as the first command-line agument.
  bool gflag = false;
  if ( argc > MIN_ARGS && strcmp( argv[ 1 ], "-g" ) == 0 ) {
    // Here's a clever trick. If -g is there, remember to print
    // graphically and remove the -g argument from the command-line.
    gflag = true;
    for ( int i = 1; i + 1 < argc; i++ )
      argv[ i ] = argv[ i + 1 ];
    argc -= 1;
  }

  // By this point, we should have just the required number of arguments.
  if ( argc != MIN_ARGS ) {
    fprintf( stderr, "usage: chessboard [-g] INPUT_FILE\n" );
    exit( EXIT_FAILURE );
  }
  
  // Make an empty chessboard, filled with zero values.
  char board[ SIZE ][ SIZE ] = {};

  // Open the input file for reading in binary.
  // ...
  
  // Read a sequence of 16-bit codes for each piece on the board and
  // fill in the board array.
  // ...

  // Print the board, using the current board printer function.
  if ( gflag )
    printGraphical( board );
  else
    printText( board );
  
  return EXIT_SUCCESS;
}
