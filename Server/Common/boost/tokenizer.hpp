#ifndef BOOST_TOKENIZER_HPP
#define BOOST_TOKENIZER_HPP

// Boost tokenizer stub
#include <string>
#include <vector>

namespace boost {
    template<typename Iterator, typename Type = std::string>
    class tokenizer {
    public:
        tokenizer(const std::string& s) : str(s) {}
        
        class iterator {
        public:
            iterator(const std::string& s, size_t pos = 0) : str(s), pos(pos) {}
            
            std::string operator*() const {
                return str.substr(pos, str.find(' ', pos) - pos);
            }
            
            iterator& operator++() {
                pos = str.find(' ', pos);
                if (pos != std::string::npos) {
                    pos++;
                    while (pos < str.size() && str[pos] == ' ') pos++;
                }
                return *this;
            }
            
            bool operator!=(const iterator& other) const {
                return pos != other.pos;
            }
            
        private:
            const std::string& str;
            size_t pos;
        };
        
        iterator begin() { return iterator(str); }
        iterator end() { return iterator(str, str.size()); }
        
    private:
        const std::string& str;
    };
}

#endif // BOOST_TOKENIZER_HPP
