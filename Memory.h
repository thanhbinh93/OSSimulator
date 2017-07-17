#ifndef MEMORY_H
#define MEMORY_H

/**
 * Provide object as memory computer
 *
 * @author
 */
class Memory
{
    public:
        Memory();
        virtual ~Memory();
		
		/**
		* Constructor for Memory class
		*
		* @param capacity
		*/
		memory(int capacity){
        this->capacity = capacity;
        }

        /**
         * Get value at position "address" of memory
         *
         * @param address
         */
         int read(int address){
             return memory[address];
         }

         /**
         * Write value into position "address" of memory
         *
         * @param address
         */
         int write(int address, int value){
             return memory[address] = value;
         }

         /**
         * Write value into position "address" of memory
         *
         * @param address
         */
         void clean(){
             Arrays.fill(data, 0);
         }


    protected:

    private:
        //int mem[2000];
		int data[];
        int capacity;

};

#endif // MEMORY_H
