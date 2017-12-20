#ifndef ALLOCPIPELINEBUFS_H
#define ALLOCPIPELINEBUFS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

template <class T> class Array {
public:

    Array()
        : mSize(0),
          mpPtr(NULL) {
          memset(&mErr, 0, sizeof(mErr));
    }


    virtual ~Array() {
        free();
    }


    virtual github_err_t alloc(uint32_t size) {
        github_err_t r = GITHUB_ERR_NONE;
        if (GITHUB_SUCCESS(r)) {
            if (size == 0) {
                r = GITHUB_ERR_INVALID_ARG;
            }
            if (mpPtr) {
                r = GITHUB_ERR_ALREADY_DONE;
            }
        }
        if (GITHUB_SUCCESS(r)) {
            mpPtr = (T*)calloc(size, sizeof(T));			
            if (!mpPtr) {
                r = GITHUB_ERR_NO_MEMORY;
            }
        }

        if (GITHUB_SUCCESS(r)) {
            mSize = size;
        }
        return r;
    }

    /**
     * Free the array.
     */
    virtual void free(void) {
        if (mpPtr) {
            ::free(mpPtr);
            mpPtr = NULL;
            mSize = 0;
        }
    }


    virtual uint32_t size() const {
        return mSize;
    }


    virtual T& operator[](uint32_t index) {
        github_err_t r = GITHUB_ERR_NONE;
        T* pData = NULL;
        if (GITHUB_SUCCESS(r)) {
            if (index > mSize) {
                r = GITHUB_ERR_INVALID_ARG;
            }
            if ((mSize == 0) || !mpPtr) {
                r = GITHUB_ERR_GENERAL;
            }
        }
        if (GITHUB_SUCCESS(r)) {
            pData = &mpPtr[index];
        } else {
            pData = &mErr;
        }
        return *pData;
    }

protected:
    uint32_t mSize;
    T* mpPtr;
    T mErr;
};

typedef struct {
  uint8_t *base;
  uint32_t data_size;        
  int heap_id;
  void * native;
} github_buf_t;


typedef struct {
  github_buf_t buf; 
  uint32_t offset[2];
  uint32_t stride;
  uint32_t scanline; 
} github_image_buf_t;


#endif
