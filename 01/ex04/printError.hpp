#ifndef PRINTERROR_HPP_
#define PRINTERROR_HPP_

enum ErrorType { argc_error, fail_to_open_infile, fail_to_open_outfile };

void printError(ErrorType);

#endif
