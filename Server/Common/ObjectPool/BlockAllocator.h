#pragma once

#include <memory>
#include <vector>

namespace ObjectPool
{
    template<typename T>
    class BlockAllocator
    {
    public:
        BlockAllocator(size_t blockSize = 32) : blockSize_(blockSize) {}
        
        T* allocate()
        {
            if (freeList_.empty())
            {
                allocateBlock();
            }
            T* ptr = freeList_.back();
            freeList_.pop_back();
            return ptr;
        }
        
        void deallocate(T* ptr)
        {
            freeList_.push_back(ptr);
        }
        
    private:
        void allocateBlock()
        {
            for (size_t i = 0; i < blockSize_; ++i)
            {
                freeList_.push_back(new T());
            }
        }
        
        size_t blockSize_;
        std::vector<T*> freeList_;
    };
}
