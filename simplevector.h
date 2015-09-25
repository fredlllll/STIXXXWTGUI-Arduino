/**********************************************************************************************
 * Arduino STIXXXWTGUI Library - Version 1.0.0
 * by Frederik Gelder <frederik.gelder@freenet.de>
 *
 * Copyright 2015 Frederik Gelder
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **********************************************************************************************/
 #ifndef SIMPLEVECTOR_h
 #define SIMPLEVECTOR_h
 
 #include <stddef.h>
 
template<typename T> class simplevector {
  public:
    simplevector() : _size(0), capacity(0), data(0) {}; // Default constructor
    ~simplevector() { free(data); }; // Destructor
    simplevector(size_t startCapacity) : _size(0), capacity(startCapacity), data(0) {
        allocCap();
    }
    simplevector(simplevector const &other) : _size(other._size), capacity(other.capacity), data(0) { // Copy constuctor
        data = (T*)malloc(capacity*sizeof(T));
        memcpy(data, other.data, size*sizeof(T));
    }
    simplevector &operator=(simplevector const &other) { // Needed for memory management
        free(data);
        _size = other._size;
        capacity = other.capacity;
        data = (T*)malloc(capacity*sizeof(T));
        memcpy(data, other.data, _size*sizeof(T));
        return *this;
    }
    void push_back(T const &x) { // Adds new value. If needed, allocates more space
        if (capacity == _size){
            resize();
        }
        data[_size++] = x;
    }
    void erase(size_t position){
        memcpy(data+position,data+position+1,((_size--)-position-1)*sizeof(T));
    }
    void erase(T elem){
        for(int i =0; i< _size;i++){
            if(data[i]== elem){
                erase(i);
                return;
            }
        }
    }
    size_t size() const { return _size; } // Size getter
    T const &operator[](size_t i) const { return data[i]; } // Const getter
    T &operator[](size_t i) { return data[i]; } // Changeable getter
  private:
    size_t _size; // Stores no. of actually stored objects
    size_t capacity; // Stores allocated capacity
    T *data; // Stores data
  
    void resize() {// Allocates double the old space
        capacity = capacity ? capacity*2 : 1;
        allocCap();
    }
    void allocCap(){
        T *newdata = (T *)malloc(capacity*sizeof(T));
        memcpy(newdata, data, _size * sizeof(T));
        free(data);
        data = newdata;
    }
};

#endif