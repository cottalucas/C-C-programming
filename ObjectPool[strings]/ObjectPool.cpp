/*

Object Pool of strings.  

Your strings should be a unique class, created by yourself.  Strings should be a character array of a set size.  You can limit each string to 256 characters long.  
There should be one object pool created which holds all the character arrays.  The size of this pool should be tunable at compile time via CONSTS.  
Implement a hashing (unique ID) solution for each string which is created.  Then when another string of that same content is created, the hash is returned and it points to the same position in the object pool.  For example: the string "bob" could be hashed as a unique 32 bit hashcode.  Then when someone else instantiated a string with "bob" as the contents, we simply return the hash of "bob".  
To perform the above you should also implement a printing function for your strings, which take as input a hash value, goes to the pool and prints the given string.  This is ultimately the benefit we get from this design pattern.  Many games use this same pattern, this way they can pass around the hashed value as a key to whatever the string is: and then they don't have to pass a STL string object around (which creates a dynamic string object on the heap each time it's passed)
Finally, create a tester function which parses a paragraph of text from the command line, splits the text based on spaces and inserts each word into the pool.

Your output should be:

A complete printout of all words and their equivalent hashes.
A stat listing the total number of words input from the user
A stat listing the total number of character arrays used in the object pool.

 */

#include "ObjectPool.h"
 
class ObjectPool
{
    private:
        std::list<Resource*> resources;
        
        static ObjectPool* instance;
        ObjectPool() {}
 
    public:
        static ObjectPool* getInstance()
        {
            if (instance == 0)
            {
                instance = new ObjectPool;
            }
            return instance;
        }
 

        Resource* getResource()
        {
            if (resources.empty())
            {
                std::cout << "Creating new." << std::endl;
                return new Resource;
            }
            else
            {
                std::cout << "Reusing existing." << std::endl;
                Resource* resource = resources.front();
                resources.pop_front();
                return resource;
            }
        }
 
        void returnResource(Resource* object)
        {
            object->reset();
            resources.push_back(object);
        }
};
 
ObjectPool* ObjectPool::instance = 0;
 
 
int main()
{
    ObjectPool* pool = ObjectPool::getInstance();
    Resource* one;
 
    //resources will be created.
    one = pool->getResource();
    one->setChar("Sentence test");
    std::cout << one->getChar() << one << std::endl;
 
    pool->returnResource(one);
 
    //resources will be reused. 
    // Notice that the value of the resource were reset back to zero.

    one = pool->getResource();
    std::cout <<  one->getChar() << one << std::endl;
 
   
    return 0;
}
