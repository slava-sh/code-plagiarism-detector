int main()
{
    for (volatile int i = 0; i < 1000000000; ++i);
    return 0;
}
