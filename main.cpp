#include <iostream>
#include <string>
#include <vector>

// bad practice but it's not a big enough project for it to matter
using namespace std;

// put functions in another file later so it's not as cluttered

// statics only deals with 3d vectors at most, so convert things into 3d vectors
void convertTo3d(vector<double>& v1);
// 3d cross product
vector<double> cross(vector<double>& r, vector<double>& F);
// dot product
double dot(vector<double>& r, vector<double>& F);
// need to print vectors too
void printVector(vector<double>& v);
// get the magnitude
double magnitude(vector<double>& v);
// convert into a unit vector
void makeUnitVector(vector<double>& v);
// find resultant of the vectors combined
vector<double> totalF(vector<vector<double>>& forces);


int main(void) {

	vector<double> test;

	convertTo3d(test);

	test[1] = 1;

	cout << "magnitude: " << magnitude(test) << "\n";
	printVector(test);


	return 0;
}

void convertTo3d(vector<double>& v1) {
	// may be a better solution like this but there are build errors
	int l = v1.size();
	if (l > 3) { return; }
	v1.insert(v1.begin() + l, 3 - l, 0.0);
}

// 3d cross product
vector<double> cross(vector<double>& r, vector<double>& F) {
	vector<double> ans;
	int rlen = r.size(), Flen = F.size();
	if (rlen < 3) {
		convertTo3d(r);
	}
	if (Flen < 3) {
		convertTo3d(F);
	}

	ans.push_back(r[1] * F[2] - r[2] * F[1]);
	ans.push_back(r[2] * F[0] - r[0] * F[2]);
	ans.push_back(r[0] * F[1] - r[1] * F[0]);

	return ans;
}
// dot product
double dot(vector<double>& r, vector<double>& F) {
	double ans = 0;
	int lim = min(r.size(), F.size());
	for (int i = 0; i < lim; ++i) {
		ans += r[i] * F[i];
	}
	return ans;
}

void printVector(vector<double>& v) {
	cout << v[0] << " i + " << v[1] << " j + " << v[2] << " k\n";
}

double magnitude(vector<double>& v) {
	// ide didn't like ^ or **, which apparently don't work
	return sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
}

void makeUnitVector(vector<double>& v) {
	double mag = magnitude(v);

	v[0] /= mag;
	v[1] /= mag;
	v[2] /= mag;
}

vector<double> totalF(vector<vector<double>>& forces) {
	vector<double> resultant(3, 0.0);

	for (int i = 0; i < forces.size(); ++i) {
		resultant[0] += forces[i][0];
		resultant[1] += forces[i][1];
		resultant[2] += forces[i][2];
	}
	return resultant;
}
