#ifndef MAX_FINDER_H_
#define MAX_FINDER_H_

struct MaxFinderInputItem {
	double x;
};

struct MaxFinderOutputItem {
	double currentMax;
	unsigned int amountMax;
};


#define MAXFINDER_OUTPUTMAXCOUNT 1
struct MaxFinderOutput {
	unsigned count;
	MaxFinderOutputItem sequence [MAXFINDER_OUTPUTMAXCOUNT];
};

struct MaxFinderParameters {
	double upperBound;
};

struct MaxFinderExtension {
	//int x_prev;
	bool exists;
};

struct MaxFinder {
	MaxFinderOutput output;
	MaxFinderParameters params;
	MaxFinderExtension extension;
};

void maxFinderInit(MaxFinder& instance, const MaxFinderParameters& params);
void maxFinderDestroy(MaxFinder& instance);
void maxFinderProcess(MaxFinder& instance, MaxFinderInputItem& input,
	MaxFinderOutput& output);

#endif