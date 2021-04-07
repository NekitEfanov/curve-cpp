#include <math.h>
#include <random>
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>

#include "helix.hpp"
#include "circle.hpp"
#include "ellipse.hpp"

#include <omp.h>

using namespace std;


int main() {  
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist_i;
    uniform_real_distribution<float> dist_f;

    size_t n = 1Ull + dist_i(gen) % 100;

    vector<shared_ptr<curve>> storage;

    for (size_t i = 0Ull; i < n; ++i) {
        int class_id = dist_i(gen) % 3;

        shared_ptr<curve> obj;

        switch (class_id)
        {
        case 0:
            obj = make_shared<circle>(abs(dist_f(gen)));
            break;
        case 1:
            obj = make_shared<ellipse>(abs(dist_f(gen)), abs(dist_f(gen)));
            break;
        case 2:
            obj = make_shared<helix>(
                    abs(dist_f(gen)), abs(dist_f(gen)), abs(dist_f(gen))
            );
            break;
        default:
            break;
        }

        storage.push_back(obj);
    }
                                                                                
    for (size_t i = 0; i < storage.size(); i++) {
        auto grad = storage[i]->grad((float)M_PI / 4.f);

        cout << "Curve " << i << " diff: " << "(" << grad[0]
            << ", " << grad[1]  << ", " << grad[2] << ")" << endl;
    }

    vector<shared_ptr<circle>> circle_storage;
    for (size_t i = 0; i < storage.size(); i++) {
        shared_ptr<circle> obj = dynamic_pointer_cast<circle>(storage[i]);

        if (obj != nullptr)
            circle_storage.push_back(obj);
    }

    sort(
        circle_storage.begin(),
        circle_storage.end(),
        [](const auto& p, const auto& q) {
            return p->R() < q->R();
        }
    );

    float sum = 0.;
    int threads_count = omp_get_max_threads();

    #pragma omp parallel for reduction(+:sum) num_threads(threads_count)
    for (int i = 0; i < circle_storage.size(); i++)
        sum += circle_storage[i]->R();

    cout << "Total radii sum: " << sum << endl;

    return 0;
}
