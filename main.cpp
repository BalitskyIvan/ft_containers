#include "vector_test.cpp"
#include "map_test.cpp"
#include "stack_tester.cpp"

#include <deque>

#define MAX_RAM 42940000
#define BUFFER_SIZE 12000

struct Buffer {
    int idx;
    char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T> {
public:
    MutantStack() {}

    MutantStack(const MutantStack<T> &src) { *this = src; }

    MutantStack<T> &operator=(const MutantStack<T> &rhs) {
        this->c = rhs.c;
        return *this;
    }

    ~MutantStack() {}

    typedef typename ft::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }

    iterator end() { return this->c.end(); }
};

int main() {
    {
//        if (argc != 2) {
//            std::cerr << "Usage: ./test seed" << std::endl;
//            std::cerr << "Provide a seed please" << std::endl;
//            std::cerr << "Count value:" << COUNT << std::endl;
//            return 1;
//        }
//        const int seed = atoi(argv[1]);
        const int seed = 5;
        srand(seed);

        ft::vector<std::string> vector_str;
        ft::vector<int> vector_int;
        ft::stack<int> stack_int;
        ft::vector<Buffer> vector_buffer;
        ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
        ft::map<int, int> map_int;

        for (int i = 0; i < COUNT; i++) {
            vector_buffer.push_back(Buffer());
        }

        for (int i = 0; i < COUNT; i++) {
            const int idx = rand() % COUNT;
            vector_buffer[(size_t)idx].idx = 5;
        }
        ft::vector<Buffer>().swap(vector_buffer);

        try {
            for (int i = 0; i < COUNT; i++) {
                const int idx = rand() % COUNT;
                vector_buffer.at((size_t)idx);
                std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" << std::endl;
            }
        }
        catch (const std::exception &e) {
          std::cout << "norm" << std::endl;
        }

        for (int i = 0; i < COUNT; ++i) {
            map_int.insert(ft::make_pair(rand(), rand()));
        }

        int sum = 0;
        for (int i = 0; i < 10000; i++) {
            int access = rand();
            sum += map_int[access];
        }
        std::cout << "should be constant with the same seed: " << sum << std::endl;

        {
            ft::map<int, int> copy = map_int;
        }
        MutantStack<char> iterable_stack;
        for (char letter = 'a'; letter <= 'z'; letter++)
            iterable_stack.push(letter);
        for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++) {
            std::cout << *it;
        }
        std::cout << std::endl;
    }
    {
      //        if (argc != 2) {
      //            std::cerr << "Usage: ./test seed" << std::endl;
      //            std::cerr << "Provide a seed please" << std::endl;
      //            std::cerr << "Count value:" << COUNT << std::endl;
      //            return 1;
      //        }
      //        const int seed = atoi(argv[1]);
      const int seed = 5;
      srand(seed);

      std::vector<std::string> vector_str;
      std::vector<int> vector_int;
      std::stack<int> stack_int;
      std::vector<Buffer> vector_buffer;
      std::map<int, int> map_int;

      for (int i = 0; i < COUNT; i++) {
        vector_buffer.push_back(Buffer());
      }

      for (int i = 0; i < COUNT; i++) {
        const int idx = rand() % COUNT;
        vector_buffer[(size_t)idx].idx = 5;
      }

      std::vector<Buffer>().swap(vector_buffer);

      try {
        for (int i = 0; i < COUNT; i++) {
          const int idx = rand() % COUNT;
          vector_buffer.at((size_t)idx);
          std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" << std::endl;
        }
      }
      catch (const std::exception &e) {
        std::cout << "norm" << std::endl;
      }

      for (int i = 0; i < COUNT; ++i) {
        map_int.insert(std::make_pair(rand(), rand()));
      }

      int sum = 0;
      for (int i = 0; i < 10000; i++) {
        int access = rand();
        sum += map_int[access];
      }
      std::cout << "should be constant with the same seed: " << sum << std::endl;

      {
        std::map<int, int> copy = map_int;
      }
      MutantStack<char> iterable_stack;
      for (char letter = 'a'; letter <= 'z'; letter++)
        iterable_stack.push(letter);
      for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++) {
        std::cout << *it;
      }
      std::cout << std::endl;
    }
    {
        make_vector_test();
        make_map_test();
        make_stack_test();
    }
    return (0);
}