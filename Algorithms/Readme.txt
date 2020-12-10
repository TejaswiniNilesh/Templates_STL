Algorithms

- Test conditions : check range of values in container : all_of, any_of, none_of, 

- Searching and counting :
ex. find - sequential search - returns index
    find_if - uses unary operator ex, is_odd : finds first odd number in sequence.
    find_if_not - uses unary operator as functor.
    search - search range in input range. Returns index.
    count - counts number of occurrences.
    count_if - uses predicate function ex. is_odd then count


- Replacing and removing :
replace - replace element with new value.
replace_if - replace with predicate ex. is_even<int>
remove - resize container after removal
remove_if - resize container after removal
v1.resize(it- v1.begin())

unique - removes duplicate entries in containers

- Modifying algorithms
copy - copy source range to destination
copy_n - copy number of items
copy_backward - copies from back to front. But result is from front to back
reverse - reverses container - uses swap function
fill - fills container with given value
fill_n - fills number of elements with given value
generate - generate(v2.begin(),v2.end(), []()->int {return rand() % 100;})

random_shuffle() - shuffle elements in place
In C++17 has deprecated random_shuffle().

random header contains class to generate random numbers as -
random_device rd;
mt19937 g(rd());
shuffle(v1.begin(),v1.end(),g);




