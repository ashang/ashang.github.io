#include <stdio.h>
#include <string.h>

// For specify int
template <int N>
class Buffer {
public:
    Buffer() {
        m_buf[0] = 0;
    }
    char* Pointer() {
        return m_buf;
    }
private:
    char m_buf[N];
};

int main()
{
    Buffer<100> buf;
    strcpy(buf.Pointer(), "Hello");
    printf("%hs\n", buf.Pointer());
    return 0;
}
