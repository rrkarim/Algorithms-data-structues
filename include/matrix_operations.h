#ifndef __MATRIX_OPERATIONS__
#define __MATRIX_OPERATIONS__

#include <inc_libs.h>
#include <vector>
namespace math {

	template <typename T>
	class Matrix {
		private:
			T a[][]
			int n, m;
		public:
			Matrix(T g[][], int n, int m) {
				this->n = n;
				this->m = m;
				for(int i = 0; i < n; ++i) 
					for(int j = 0; j < m; ++j)
						a[i][j] = g[i][j];
			}
			int get_rank() {
				int rank = MAX(this->n, this->m);
				std::vector<char> v(this->n);

				for(int i = 0; i < m; ++i) {
					int j;
				}
			}
	}

}

#endif