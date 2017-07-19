#ifndef INDEXOUTOFBOUNDSEXCEPTION_H
#define INDEXOUTOFBOUNDSEXCEPTION_H


class IndexOutOfBoundsException : public exception
{
    public:
        const char* what() const throw();
};

#endif // INDEXOUTOFBOUNDSEXCEPTION_H
