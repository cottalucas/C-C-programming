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


#include <string>
#include <iostream>
#include <list>
 
class Resource
{
    int value;
 
    public:
        Resource()
        {
            value = 0;
        }
 
        void reset()
        {
            value = 0;
        }
 
        int getValue()
        {
            return value;
        }
 
        void setValue(int number)
        {
            value = number;
        }
};
 
/* Note, that this class is a singleton. */
class ObjectPool
{
    private:
        std::list<Resource*> resources;
        
        static ObjectPool* instance;
        ObjectPool() {}
 
    public:
        /**
         * Static method for accessing class instance.
         * Part of Singleton design pattern.
         *
         * @return ObjectPool instance.
         */
        static ObjectPool* getInstance()
        {
            if (instance == 0)
            {
                instance = new ObjectPool;
            }
            return instance;
        }
 
        /**
         * Returns instance of Resource.
         * 
         * New resource will be created if all the resources
         * were used at the time of the request.
         *
         * @return Resource instance.
         */
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
 
        /**
         * Return resource back to the pool.
         *
         * The resource must be initialized back to
         * the default settings before someone else
         * attempts to use it.
         *
         * @param object Resource instance.
         * @return void
         */
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
    Resource* two;
 
    /* Resources will be created. */
    one = pool->getResource();
    one->setValue(10);
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
 
    two = pool->getResource();
    two->setValue(20);
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;
 
    pool->returnResource(one);
    pool->returnResource(two);
 
    /* Resources will be reused. 
     * Notice that the value of both resources were reset back to zero.
     */
    one = pool->getResource();
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
 
    two = pool->getResource();
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;
   
    return 0;
}
