transform : 
- std::transform is a function applied on each element in a range
- Prototype : transform on a ragne

template<typename InputIterator, typename OutputIterator, typename UnaryOperation>
OutputIterator transform(InputIterator first1, InputIterator last1,
                         OutputIterator result,
                         UnaryOperation op);


- Prototype :  transform on two ranges


template<typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryOperation>
OutputIterator transform(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2,
                         OutputIterator result,
                         BinaryOperation op);




Lambda : 
- anonymous functions in C++11 is called lambda functions
- Inline function we can write in order to pass into another function.
-  Can be used in tranform, for_each


string :
- ::toupper - Its macro. Converts string to upper.
- string works 
- Use functors in transform to operate on each element in string using transform.


Binary operator : 


unary operation(1)	
template <class InputIterator, class OutputIterator, class UnaryOperation>
  OutputIterator transform (InputIterator first1, InputIterator last1,
                            OutputIterator result, UnaryOperation op);
binary operation(2)	
template <class InputIterator1, class InputIterator2,
          class OutputIterator, class BinaryOperation>
  OutputIterator transform (InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, OutputIterator result,
                            BinaryOperation binary_op);

transform from one type to another type
- 
