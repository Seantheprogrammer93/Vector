#pragma once
template<typename T>
class Vector
{
	T* mData; // Arbitrary data to be inserted into the vector.
	int mSize; // Size of the Vector.
	int mCapacity; // How many elements the vector can hold.
	T mUndefined;

public:
	Vector() // O(1), this is the Vector class constructor
	{
		mSize = 0;
		mCapacity = 15;
		mData = new T[mCapacity];
	}

	Vector(const Vector<T>& tOther) : Vector() // O(n), Copy constructor
	{
		Reserve(tOther.Capacity());

		for (int i = 0; i < tOther.Size(); i++)
		{
			mData[i] = tOther.At(i);
		}

		mSize = tOther.Size();
	}

	Vector& operator = (const Vector<T>& tRHS) // O(n)
	{
		Reserve(tRHS.Capacity());

		for (int i = 0; i < tRHS.Size(); i++)
		{
			mData[i] = tRHS.At(i);
		}

		mSize = tRHS.Size();

		return *this;
	}

	~Vector() // Vector class destructor
	{
		delete[] mData;
	}

	void PushBack(const T& tItem) // O(1), Push elements to the back of the vector.
	{
		if (mSize == mCapacity)
		{
			Reserve(mCapacity * 2);
		}
		else
		{
			mData[mSize] = tItem;
			mSize++;
		}
	}

	void PopBack() // O(1), Pop elements off of the vector
	{
		if (mSize > 0)
		{
			mSize--;
		}
	}

	T At(int tWhere) const // O(1), Find an element at a specific index in the vector.
	{
		if (tWhere >= mSize || tWhere < 0)
		{
			return mUndefined;
		}
		else
		{
			return mData[tWhere];
		}
	}

	void Clear() // O(1), Clear all elements from the vector.
	{
		mSize = 0;
	}

	int Size() const // O(1), Returns the size of the vector.
	{
		return mSize;
	}

	void Reserve(int tCount) // O(n), Reserves memory for the vector.
	{
		int tPreviousSize = mSize;

		if (tCount < tPreviousSize)
		{
			tPreviousSize = tCount;
		}

		T* tData = new T[tCount];

		for (int i = 0; i < tPreviousSize; i++)
		{
			tData[i] = mData[i];
		}

		delete[] mData;

		mSize = tPreviousSize;
		mData = tData;
		mCapacity = tCount;
	}

	int Capacity() const // O(1), Returns the number of elements that the vector can hold.
	{
		return mCapacity;
	}
};
