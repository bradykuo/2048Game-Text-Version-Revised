#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class FileCorruptedException : public std::exception {
public:
    const char* what() const throw() {
        return "File is corrupted or has invalid format";
    }
};

#endif // EXCEPTION_H