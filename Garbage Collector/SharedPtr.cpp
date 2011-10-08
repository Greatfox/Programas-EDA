

#include "SharedPtr.h"

template<typename ElemType> inline SharedPtr<ElemType>::SharedPtr(
		ElemType *resource = NULL) {
	resource_ = resource;
	referencecount_ = new int(1);
}

template<typename ElemType> inline ElemType & SharedPtr<ElemType>::operator *() const {
	return *resource_;
}

template<typename ElemType> inline ElemType *SharedPtr<ElemType>::operator ->() const {
	return &resource_;
}

template<typename ElemType> inline SharedPtr<ElemType> & SharedPtr<ElemType>::operator =(
		const SharedPtr & other) {
	if (resource_ != other.resource_) {
		Detach();
		resource_ = other.resource_;
		referencecount_ = other.referencecount_;
		++(*referencecount_);
	}
	return *this;
}

template<typename ElemType> inline SharedPtr<ElemType> & SharedPtr<ElemType>::operator =(
		ElemType *other) {
	Detach();
	resource_ = other;
	return *this;
}

template<typename ElemType> inline ElemType *SharedPtr<ElemType>::GetPointer() const {
	return resource_;
}

template<typename ElemType> inline size_t SharedPtr<ElemType>::GetReferenceCount() const {
	return *referencecount_;
}

/*template<typename ElemType> inline SharedPtr<ElemType>::SharedPtr<ElemType>(
		const SharedPtr<ElemType> & other) {
	resource_ = other.resource_;
	referencecount_ = other.referencecount_;
	++(*referencecount_);
}
*/
template<typename ElemType> inline void SharedPtr<ElemType>::Detach() {
	if (*referencecount_ == 1) {
		delete resource_;
	} else {
		resource_ = NULL;
		--(*referencecount_);
		referencecount_ = new int(1);
	}
}

template<typename ElemType> inline SharedPtr<ElemType>::~SharedPtr<ElemType>() {
	if (*referencecount_ == 1) {
		delete resource_;
		delete referencecount_;
	} else {
		--(*referencecount_);
	}
}
