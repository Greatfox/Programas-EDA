

#ifndef SHAREDPTR_H_
#define SHAREDPTR_H_

#include <iostream>

using namespace std;

/*
 * Smart Pointer que implementa un tipo de estrategia por conteo de referencias.
 * Permite que varios SharedPtrs puedan acceder al mismo recurso compartido.
 * Cuando el último puntero es eliminado, se elimina y libera el recurso.
 */
template<typename ElemType>
class SharedPtr {
private:
	ElemType * resource_;
public:
	int *referencecount_;
	explicit SharedPtr(ElemType* resource);

	
	~SharedPtr();

	
	ElemType& operator*() const;
	ElemType* operator->() const;

	
	SharedPtr &operator=(const SharedPtr& other);
	SharedPtr &operator=(ElemType* other);
	SharedPtr(const SharedPtr& other);

	
	ElemType* GetPointer() const;

	
	size_t GetReferenceCount() const;

	
	void Detach();

};

#endif /* SHAREDPTR_H_ */
