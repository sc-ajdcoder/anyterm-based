// examples/http_get_gunzip.cc
// This file is part of libpbe; see http://svn.chezphil.org/libpbe/
// (C) 2008 Philip Endecott

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.


#include "HttpClient.hh"
#include "Gunzipper.hh"

#include "Exception.hh"

#include <iostream>
#include <string>

using namespace pbe;
using namespace std;



int main(int argc, char* argv[])
{
  try { try {

    if (argc!=3) {
      cerr << "Usage: http_get_gunzip <URI.bz> <fn>\n";
      exit(1);
    }

    string uri = argv[1];
    string fn = argv[2];

    try {
      HttpClient http_client;
      http_client.get_gunzip_save(uri,fn);
    }
    catch (Gunzipper::InvalidData& E) {
      cerr << "Gunzipper::InvalidData\n";
      exit(1);
    }

    return 0;

  } RETHROW_MISC_EXCEPTIONS }
  catch (Exception& E) {
    E.report(cerr);
    exit(E.exit_status);
  }
}
