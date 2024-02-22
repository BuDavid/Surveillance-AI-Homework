class SortingStrategy {
public:
	virtual void sort(std::vector<int>& vec) = 0;
};

class Bubble : public SortingStrategy {
public:
	void sort(std::vector<int>& vec) override;
};

class Insert : public SortingStrategy {
public:
	void sort(std::vector<int>& vec) override;
};

class Select : public SortingStrategy {
public:
	void sort(std::vector<int>& vec) override;
};

class Quick : public SortingStrategy {
public:
	void sort(std::vector<int>& vec) override;

private:
	void quicksort(std::vector<int>& vec, int low, int high);
	int partition(std::vector<int>& vec, int low, int high); 
};

/* void init_options(std::vector<SortingOption>& options); */

