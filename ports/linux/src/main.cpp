#include <stdio.h>
#include <miniSystem.hpp>
#include <console.hpp>
#include <stream.hpp>

static void fault_handler(void *, const char *msg)
{
    fprintf(stderr, "FATAL: %s\n", (msg ? msg : "no message."));
    fflush(stderr);
    exit(1);
}

class ConsoleIf : public StreamIf<char>
{
public:
    bool readable = false;
    bool writable = true;

    ConsoleIf() {}
    ~ConsoleIf() {}

    void write(const std::vector<char> &src)
    {
        std::string msg(src.begin(), src.end());
        printf("%s\n", msg.c_str());
    }

    void read(std::vector<char> &dst)
    {
    }
};

int main()
{

    consoleStream.init(new ConsoleIf());

    MiniSystem ms(fault_handler);

    printf("Result: %d.\n", ms.eval("console.log('Hello world!')"));
}