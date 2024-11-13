template<class T>
void ArrayList<T>::ensureCapacity(int cap){
    if (cap == capacity) {
        int new_capacity = capacity * 1.5; 
        T* new_array = new T[new_capacity];
        for (int i = 0; i < count; i++) {
            new_array[i] = data[i];
        }
        delete[] data;
        data = new_array;
        capacity = new_capacity;
    }
}
template <class T>
void ArrayList<T>::add(T e) {
    ensureCapacity(count);
    data[count] = e;
    count++;
}
template<class T>
void ArrayList<T>::add(int index, T e) {
    if (index < 0 || index > count) {
        throw std::out_of_range("the input index is out of range!");
    }
    ensureCapacity(count);
    for (int i = count; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = e;
    count++;
}
template<class T>
int ArrayList<T>::size() {
    return count;
}
