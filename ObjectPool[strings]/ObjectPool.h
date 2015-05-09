class Resource
{
    size_t size; 
    int* array; //pointer
     
    public:
        Resource(size_t S = 0)
        {
            size = S;
            array = new char[size];
            
        {
        ~Resource()
        {
            delete[] array;
        }
        void reset()
        {
            array <- "";
        }
        int getChar()
        {
            return array;
        }
        void setChar()
        {
            array <- "";
        }

};
