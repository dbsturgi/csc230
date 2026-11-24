import java.io.File;
import java.io.FileInputStream;
import java.util.Scanner;
import java.util.ArrayList;

import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;

/** Decrypt an AES-encrypted text file with a password provided on the
    command line (probably a bad idea).  The key and text file are
    padded with zeros if necessary. */
public class Decrypt {
  public static byte[] readBinary( String fname ) throws Exception {
    FileInputStream input = new FileInputStream( fname );

    // Sequence of bytes read from the file.
    ArrayList< Byte > seq = new ArrayList<>();

    // Read the file's contents, in 1KB blocks.
    byte[] buffer = new byte [ 1024 ];
    int len;
    while ( ( len = input.read( buffer ) ) > 0 )
      for ( int i = 0; i < len; i++ )
        seq.add( buffer[ i ] );

    // Convert to a byte array (could I get toAray() to do this?)
    byte[] result = new byte [ seq.size() ];
    for ( int i = 0; i < result.length; i++ )
      result[ i ] = seq.get( i );
    return result;
  }

  public static void main( String[] args ) throws Exception {
    if ( args.length != 2 ) {
      System.err.println( "usage: java Decrypt KEY INPUT-FILENAME" );
      System.exit( 1 );
    }

    // Key given on the command line, padded to exactly 16 bytes.
    byte[] rawKey = new byte [ 16 ];
    {
      int pos = 0;
      while ( pos < rawKey.length && pos < args[ 0 ].length() ) {
        rawKey[ pos ] = (byte) args[ 0 ].charAt( pos );
        pos += 1;
      }
      
      while ( pos < rawKey.length )
        rawKey[ pos++ ] = 0;
    }
    
    // Make an AES key object from this byte array.
    SecretKey key = new SecretKeySpec( rawKey, "AES" );

    // Make a cipher object that can decrypt with this key.
    Cipher cipher = Cipher.getInstance( "AES/ECB/NoPadding" );
    cipher.init( Cipher.DECRYPT_MODE, key );

    // Read the contents of the input file.
    byte[] rawMsg = readBinary( args[ 1 ] );

    // Decrypt it with the given key.
    byte[] rawPlaintext = cipher.doFinal( rawMsg );

    // Convert to a string, discarding null bytes (should be at the end).
    StringBuilder builder = new StringBuilder();
    for ( int i = 0; i < rawPlaintext.length; i++ )
      if ( rawPlaintext[ i ] != 0 )
        builder.append( (char) rawPlaintext[ i ] );

    // Print the resulting string.
    System.out.print( builder.toString() );
  }
}
