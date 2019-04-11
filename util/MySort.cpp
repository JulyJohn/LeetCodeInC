//
// Created by yzjhh on 2019/2/18.
//

#include "MySort.h"

namespace leetcode {

    /**
     * 插入排序
     *
     * 时间复杂度：平均O(n^2)，最好可以达到O(n)
     * 空间复杂度：O(1)
     * 稳定性：稳定
     *
     * 原理：遍历数组，遍历到i时，a0,a1...ai-1是已经排好序的，取出ai，从ai-1开始向前和每个比较大小，如果小于，则将此位置元素向后移动，继续先前比较，如果不小于，则放到正在比较的元素之后。可见相等元素比较是，原来靠后的还是拍在后边，所以插入排序是稳定的。
     *
     * note: 当待排序的数据基本有序时，插入排序的效率比较高，只需要进行很少的数据移动。
     * */
    void insertion_sort(vector<int> &a, int n) {
        for (int i = 1; i < n; ++i) {
            int tmp = a[i];
            int j = i - 1;
            while (j >= 0) { // i以前的序列是排序好的，所以在这段序列中找到合适的位置插入即可
                if (a[j] > tmp) {
                    a[j + 1] = a[j];
                } else {
                    break;
                }
                j--;
            }
            a[j + 1] = tmp;
        }
    }

    /**
     * 选择排序
     *
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(1)
     * 稳定性：不稳定
     *
     * 原理：遍历数组，遍历到i时，a0,a1...ai-1是已经排好序的，然后从i到n选择出最小的，记录下位置，如果不是第i个，则和第i个元素交换。此时第i个元素可能会排到相等元素之后，造成排序的不稳定。
     *
     * note: 算法的稳定性定义为,对于待排序列中相同项的原来次序不能被算法改变则称该算法稳定.
     * */
    void selection_sort(vector<int> &a, int n) {
        for (int i = 0; i < n; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < a[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                swap(a[min_idx], a[i]);
            }
        }
    }

    /**
     * 冒泡排序
     *
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(1)
     * 稳定性：稳定
     *
     * 原理：相邻两节点进行比较，大的向后移一个，经过第一轮两两比较和移动，最大的元素移动到了最后，第二轮次大的位于倒数第二个，依次进行。
     * */
    void bubble_sort(vector<int> &a, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n - i; ++j) {
                if (a[j] < a[j - 1]) {
                    swap(a[j], a[j-1]);
                }
            }
        }
    }

    /**
     * 冒泡排序 优化1
     *
     * 时间复杂度：平均O(n^2)，最好可以达到O(n)
     * 空间复杂度：O(1)
     *
     * 原理：如果一趟比较下来没有任何数据交换，说明数据已经是有序状态，那么停止循环。
     * */
    void bubble_sort1(vector<int> &a, int n) {
        for (int i = 0; i < n; ++i) {
            bool has_changed = false;
            for (int j = 1; j < n - i; ++j) {
                if (a[j] < a[j - 1]) {
                    swap(a[j], a[j-1]);
                    has_changed = true;
                }
            }
            if (!has_changed) {
                return;
            }
        }
    }

    /**
     * 冒泡排序 优化2
     *
     * 原理：如果一趟比较中到某个位置以后不再有任何数据交换，说明该位置以后的数据已经是有序状态，那么下一趟比较只需要到该位置即可。
     * */
    void bubble_sort2(vector<int> &a, int n) {
        int end_idx = n;
        for (int i = 0; i < n; ++i) {
            bool has_changed = false;
            int pos = 0;
            for (int j = 1; j < end_idx; ++j) {
                if (a[j] < a[j - 1]) {
                    swap(a[j], a[j-1]);
                    pos = j;
                    has_changed = true;
                }
            }
            if (!has_changed) {
                return;
            }
            end_idx = pos;
        }
    }

    /**
     * 快速排序
     *
     * 时间复杂度：最坏情况O(n^2)(恰好逆序),最好情况O(n*logn),平均情况O(n*logn)
     * 空间复杂度：同时间复杂度
     * 稳定性：不稳定
     *
     * 原理：

          1．先从数列中取出一个数作为基准数。

          2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。

          3．再对左右区间重复第二步，直到各区间只有一个数。
     *
     * note: 可以用挖坑填数的思想来理解
     *
         1．i =L; j = R; 将基准数挖出形成第一个坑a[i]。

         2．j--由后向前找比它小的数，找到后挖出此数填前一个坑a[i]中。

         3．i++由前向后找比它大的数，找到后也挖出此数填到前一个坑a[j]中。

         4．再重复执行2，3二步，直到i==j，将基准数填入a[i]中。

      * 一种优化：小区间优化
      *
           当划分的子序列很小的时候(一般认为小于13个元素左右时)，我们在使用快速排序对这些小序列排序反而不如直接插入排序高效。
           因为快速排序对数组进行划分最后就像一颗二叉树一样，当序列小于13个元素时我们再使用快排的话就相当于增加了二叉树的最后几层的结点数目，增加了递归的次数。
           所以我们在当子序列小于13个元素的时候就改用直接插入排序来对这些子序列进行排序。
     * */
    void quick_sort_insertion(vector<int> &a, int lo, int hi) {
        for (int i = lo + 1; i <= hi; ++i) {
            int tmp = a[i];
            int j = i - 1;
            while (j >= lo) {
                if (tmp < a[j]) {
                    a[j + 1] = a[j];
                } else {
                    break;
                }
                j--;
            }
            a[j + 1] = tmp;
        }
    }

    // 挖坑法
    void quick_sort_partion1(vector<int> &a, int lo, int hi) {
//        if (lo >= hi) {
//            return;
//        }
        // 小区间优化
        int M = 13;
        if (hi - lo + 1 < M) {
            quick_sort_insertion(a, lo, hi);
            return;
        }
        int i = lo;
        int j = hi;
        int base = a[lo];
        while (i < j) {
            while (j > i && a[j] >= base) {
                j--;
            }
            if (j > i) {
                a[i++] = a[j];
            }
            while (i < j && a[i] < base) {
                i++;
            }
            if (i < j) {
                a[j--] = a[i];
            }
        }
        a[i] = base;
        quick_sort_partion1(a, lo, i - 1);
        quick_sort_partion1(a, i + 1, hi);
    }

    // 双向切分法
    void quick_sort_partion2(vector<int> &a, int lo, int hi) {
        if (lo >= hi) { // 递归结束的条件
            return;
        }
        int lt = lo;
        int gt = hi + 1;
        while (1) {
            while (a[++lt] < a[lo]) {
                if (lt == hi) {
                    break;
                }
            }
            while (a[--gt] > a[lo]) {
                if (gt == lo) {
                    break;
                }
            }
            if (lt >= gt) {
                break;
            }
            swap(a[lt], a[gt]);
        }
        // 最终交换时，满足a[gt]<=base，故而将a[gt]与base交换
        swap(a[lo], a[gt]);
        quick_sort_partion2(a, lo, gt - 1);
        quick_sort_partion2(a, gt + 1, hi);
    }

    // 三向切分，三个指针lt、i、gt，最终的目的是使lt和gt分别成为中间数的上下界，从而达到a[lo]<...<a[lt]=...=a[i]=...=a[gt]<...<a[hi]
    void quick_sort_partion3(vector<int> &a, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        int lt = lo;
        int i = lo + 1;
        int gt = hi;
        while (i <= gt) {
            if (a[i] < a[lo]) {
                swap(a[i++], a[lt++]);
            } else if (a[i] > a[lo]) {
                swap(a[i], a[gt--]);
            } else {
                i++;
            }
        }
        quick_sort_partion3(a, lo, lt - 1);
        quick_sort_partion3(a, gt + 1, hi);
    }

    void quick_sort(vector<int> &a, int n) {
//        quick_sort_partion1(a, 0, n - 1); // 挖坑法，最好理解
//        quick_sort_partion2(a, 0, n - 1); // 双向切分法，经典
        quick_sort_partion3(a, 0, n - 1); // 三向切分法，针对重复数字较多的情况的优化
    }

    /**
     *
     * 堆排序
     *
     * 时间复杂度：建堆O(n)，更改堆O(n*logn)
     * 空间复杂度：O(1)
     * 稳定性：稳定
     *
     * note:
     * 完全二叉树：假设一个二叉树有n层，满足
     *           1. 第1到n-1层的每个节点都达到最大的个数；
     *           2. 第n层的排列是从左往右依次排开的，那么就称其为完全二叉树.
     *
     * 堆：本身就是一个完全二叉树，满足任何一非叶节点的关键字不大于或者不小于其左右孩子节点的关键字。即
     *     1. 当二叉树的每个节点都大于等于它的子节点的时候，称为大顶堆，
     *     2. 当二叉树的每个节点都小于它的子节点的时候，称为小顶堆，上图即为小顶堆。
     *
     * */
    void adjust_heap(vector<int> &a, int lo, int hi) {

        for (int cur = lo, next = lo * 2 + 1; next <= hi; cur = next, next = next * 2 + 1) {
            //先比较两个子节点的大小，取较大者与当前节点比较
            if (next < hi && a[next] < a[next + 1]) {
                next++;
            }
            if (a[cur] < a[next]) {
                swap(a[cur], a[next]);
            } else {
                break;
            }
        }
    }

    void heap_sort(vector<int> &a, int n) {
        // 建立最大堆
        for (int i = n / 2 - 1; i >= 0; --i) {
            adjust_heap(a, i, n - 1);
        }

        // 堆顶元素即为最大值，将其移到数组的末尾，然后再调整堆使之维持最大堆的状态
        for (int i = n - 1; i >= 0; --i) {
            swap(a[0], a[i]);
            adjust_heap(a, 0, i - 1);
        }
    }

    /**
     * 计数排序（实际上是桶排序的一个特例）
     *
     * 时间复杂度：O(n+k)，其中k为桶的数量，当k<=n时，时间复杂度就变成了O(n)
     * 空间复杂度：O(2*n+k)，需要一个额外数组
     *
     * 原理：考虑待排序数组中的某一个元素a，如果数组中比a小的元素有s个，那么a在最终排好序的数组中的位置将会是s+1，
     *      如何知道比a小的元素有多少个，肯定不是通过比较来得到，而是通过数字本身的属性，
     *      即累加数组中最小值到a之间的每个数字出现的次数（未出现则为0），而每个数字出现的次数可以通过扫描一遍数组获得。
     *
     * 计数排序的步骤：
     *  1. 找出待排序的数组中最大和最小的元素（计数数组C的长度为max-min+1，其中位置0存放min，依次填充到最后一个位置存放max）
     *  2. 统计数组中每个值为i的元素出现的次数，存入数组C的第i项
     *  3. 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
     *  4. 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1（反向填充是为了保证稳定性）
     *
     * note: 适合数据分布集中的排序，如果数据太分散，会造成空间的大量浪费，
     *       假设数据为（1,2,3,1000000），这就需要1000000的额外空间，并且有大量的空间浪费和时间浪费。
     *       常见的应用有【年龄排序问题】
     *
     * */
    // 找出最大最小值(编程之美，时间复杂度为O(1.5n))
    void findMinMax(vector<int> &a, int n, int &min, int &max) {

        if (n == 0) {
            return;
        }

        min = INT32_MAX;
        max = INT32_MIN;

        int tmp_max, tmp_min;
        for (int i = 1; i < n; i += 2) {
            tmp_max = a[i] > a[i - 1] ? a[i] : a[i - 1];
            tmp_min = a[i] < a[i - 1] ? a[i] : a[i - 1];
            max = max > tmp_max ? max : tmp_max;
            min = min < tmp_min ? min : tmp_min;
        }

        // 防止size为奇数的情况
        max = max > a[n - 1] ? max : a[n - 1];
        min = min < a[n - 1] ? min : a[n - 1];
    }

    void count_sort(vector<int> &a, int n) {
        vector<int> b(a);

        int min, max;
        findMinMax(b, n, min, max);

        int numRange = max - min + 1;
        vector<int> bucket(numRange);

        // 给每个桶初始化为0
        for (int i = 0; i < numRange; ++i) {
            bucket[i] = 0;
        }

        // 遍历a，将a中元素放到对应位置的桶中
        for (int i = 0; i < n; ++i) {
            bucket[b[i] - min]++;
        }

        // 统计桶的每个位置之前的个数
        for (int i = 1; i < numRange; ++i) {
            bucket[i] += bucket[i - 1];
        }

        for (int i = n - 1; i >= 0; --i) {
            int v = b[i];
            int idx = bucket[v - min] - 1;
            a[idx] = v;
            bucket[v - min]--;
        }
    }


    /**
     * 桶排序
     *
     * 时间复杂度：桶排序的平均时间复杂度为线性的O(N+C)，其中C=N*(logN-logM)。如果相对于同样的N，桶数量M越大，其效率越高，最好的时间复杂度达到O(N)。
     * 空间复杂度：当然桶排序的空间复杂度为O(N+M)，如果输入数据非常庞大，而桶的数量也非常多，则空间代价无疑是昂贵的。
     * 稳定性：稳定
     *
     * 原理：将所有元素按区间划分到各个桶中去，然后再对各个桶中的元素排序，最后merge
     *
     * */
    void merge_sorted_array(vector<int> &a, int m, vector<int> &b, int n) {
        if (n < 1) {
            return;
        }
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (k >= 0) {
            if (i < 0) {
                a[k--] = b[j--];
            } else if (a[i] > b[j]) {
                a[k--] = a[i--];
            } else if (a[i] < b[j]) {
                a[k--] = b[j--];
            }
        }
    }

    void bucket_sort(vector<int> &a, int n) {
        if (n < 1) {
            return;
        }
        int min, max;
        findMinMax(a, n, min, max);
        int bucket_nums = 10;
        int bucket_size =
                (max - min + 1) % bucket_nums ? (max - min + 1) / bucket_nums + 1 : (max - min + 1) / bucket_nums;
        vector <vector<int>> bucket(bucket_nums);

        // 将a中元素分别放入到位置合适的桶中
        for (int i = 0; i < n; ++i) {
            int idx = (a[i] - min) / bucket_size;
            bucket[idx].push_back(a[i]);
        }

        int sorted_count = 0;
        for (int i = 0; i < bucket_nums; ++i) {
            int cur_bucket_size = bucket[i].size();
            if (cur_bucket_size == 0) {
                continue;
            }
            quick_sort(bucket[i], cur_bucket_size);
            merge_sorted_array(a, sorted_count, bucket[i], cur_bucket_size);
            sorted_count += cur_bucket_size;
        }
    }

    /**
     * 归并排序
     *
     * 时间复杂度：O(n*logn)
     * 空间复杂度：O(1)
     * 稳定性：稳定
     *
     * 原理：分治，将数组不断对半分成两部分，直到不能再继续分，最后通过比较进行合并
     * */

    void merge_sort_merge(vector<int> &a, int lo, int mid, int hi, vector<int> &b) {
        int i = lo;
        int j = mid + 1;
        for (int k = lo; k <= hi; ++k) {
            b[k] = a[k];
        }
        for (int k = lo; k <= hi; ++k) {
            if (i > mid) {
                a[k] = b[j++];
            } else if (j > hi) {
                a[k] = b[i++];
            } else if (b[i] < b[j]) {
                a[k] = b[i++];
            } else {
                a[k] = b[j++];
            }
        }
    }

    void merge_sort_sub(vector<int> &a, int lo, int hi, vector<int> &b) {
        if (lo >= hi) {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        merge_sort_sub(a, lo, mid, b);
        merge_sort_sub(a, mid + 1, hi, b);
        merge_sort_merge(a, lo, mid, hi, b);
    }

    void merge_sort(vector<int> &a, int n) {
        vector<int> tmp(a);
        merge_sort_sub(a, 0, n - 1, tmp);
    }

} // namespce leetcode


