cmake_minimum_required(VERSION 2.8)
project(LeetcodeInCplus)

# flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread")

if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif ()

# helloworld template
#add_executable(HelloWorld HelloWorld.cpp util/MySort.cpp util/BinTree.cpp util/BinarySearch.cpp)

# basic data structure
#add_executable(BinTree BinTree.cpp) # bintree

# week1
#add_executable(Monotonic_Array week1/Monotonic_Array.cpp)
#add_executable(Increasing_Order_Search_Tree week1/Increasing_Order_Search_Tree.cpp)
#add_executable(Roman_to_Integer week1/Roman_to_Integer.cpp)

# week2
#add_executable(Valid_Permutations_for_DI_Sequence week2/Valid_Permutations_for_DI_Sequence.cpp)

# dp
#add_executable(Bitwise_ORs_of_Subarrays week1/Bitwise_ORs_of_Subarrays.cpp)

# string
#add_executable(Orderly_Queue week1/Orderly_Queue.cpp)
#add_executable(Numbers_At_Most_N_Given_Digit_Set week2/Numbers_At_Most_N_Given_Digit_Set.cpp)
#add_executable(Longest_Common_Prefix week2/Longest_Common_Prefix.cpp)

# double pointer
#add_executable(Two_Sum_II double_pointer/Two_Sum_II_Input_array_is_sorted.cpp)
#add_executable(Sum_of_Square_Numbers double_pointer/Sum_of_Square_Numbers.cpp)
#add_executable(Valid_Palindrome_II double_pointer/Valid_Palindrome_II.cpp)
#add_executable(Merge_Sorted_Array double_pointer/Merge_Sorted_Array.cpp)
#add_executable(Linked_List_Cycle double_pointer/Linked_List_Cycle.cpp)
#add_executable(Linked_List_Cycle_II double_pointer/Linked_List_Cycle_II.cpp)
#add_executable(Longest_Word_in_Dictionary_through_Deleting double_pointer/Longest_Word_in_Dictionary_through_Deleting.cpp)
#add_executable(Longest_Palindromic_Substring double_pointer/Longest_Palindromic_Substring.cpp)
#add_executable(Tree_Sum double_pointer/Tree_Sum.cpp)

# sort
#add_executable(Kth_Largest_Element_in_an_Array sort/Kth_Largest_Element_in_an_Array.cpp)
#add_executable(Top_K_Frequent_Elements sort/Top_K_Frequent_Elements.cpp)
#add_executable(Sort_Characters_By_Frequency sort/Sort_Characters_By_Frequency.cpp)
#add_executable(Sort_Colors sort/Sort_Colors.cpp)
#add_executable(Top_K_Words sort/Top_K_Words.cpp)
#add_executable(Top_K_Numbers sort/Top_K_Numbers.cpp)

# greedy algorithm
#add_executable(Assign_Cookies greedy_algorithm/Assign_Cookies.cpp)
#add_executable(Non_overlapping_Intervals greedy_algorithm/Non_overlapping_Intervals.cpp)
#add_executable(Merge_Intervals greedy_algorithm/Merge_Intervals.cpp)

# dp
#add_executable(Different_Ways_to_Add_Parentheses partion/Different_Ways_to_Add_Parentheses.cpp)
#add_executable(Interleaving_String other/Interleaving_String.cpp)
#add_executable(Max_Difference_In_An_Array dynamic_programming/Max_Difference_In_An_Array.cpp)
#add_executable(Max_Common_SubString dynamic_programming/Max_Common_SubString.cpp)
#add_executable(Longest_Increasing_Subsequence dynamic_programming/Longest_Increasing_Subsequence.cpp)
#add_executable(Maximum_Length_of_Pair_Chain dynamic_programming/Maximum_Length_of_Pair_Chain.cpp)
#add_executable(MaxSubMatrix dynamic_programming/MaxSubMatrix.cpp)
#add_executable(Longest_Palindromic_Subsequence dynamic_programming/Longest_Palindromic_Subsequence.cpp)
#add_executable(Maximum_sum_alternating_subsequence dynamic_programming/Maximum_sum_alternating_subsequence.cpp)

# binary_search
#add_executable(PowerOfDouble sword_offer/PowerOfDouble.cpp)

# linkedlist
#add_executable(Intersection_of_Two_Linked_Lists linked_list/Intersection_of_Two_Linked_Lists.cpp)
#add_executable(Merge_Two_Sorted_Lists linked_list/Merge_Two_Sorted_Lists.cpp)
#add_executable(Remove_Duplicates_from_Sorted_List linked_list/Remove_Duplicates_from_Sorted_List.cpp)
#add_executable(Remove_Nth_Node_From_End_of_List linked_list/Remove_Nth_Node_From_End_of_List.cpp)
#add_executable(Swap_Nodes_in_Pairs linked_list/Swap_Nodes_in_Pairs.cpp)
#add_executable(Add_Two_Numbers_II linked_list/Add_Two_Numbers_II.cpp)
#add_executable(Palindrome_Linked_List linked_list/Palindrome_Linked_List.cpp)
#add_executable(Split_Linked_List_in_Parts linked_list/Split_Linked_List_in_Parts.cpp)
#add_executable(Odd_Even_Linked_List linked_list/Odd_Even_Linked_List.cpp)
#add_executable(Sort_List linked_list/Sort_List.cpp)
#add_executable(Insertion_Sort_List linked_list/Insertion_Sort_List.cpp)
#add_executable(Delete_Duplicate_LinkedList_Node sword_offer/Delete_Duplicate_LinkedList_Node.cpp)

# tree
#add_executable(Maximum_Depth_of_Binary_Tree tree/Maximum_Depth_of_Binary_Tree.cpp util/BinTree.cpp)
#add_executable(Balanced_Binary_Tree tree/Balanced_Binary_Tree.cpp)
#add_executable(Diameter_of_Binary_Tree tree/Diameter_of_Binary_Tree.cpp)
#add_executable(Invert_Binary_Tree tree/Invert_Binary_Tree.cpp)
#add_executable(Merge_Two_Binary_Trees tree/Merge_Two_Binary_Trees.cpp)
#add_executable(Path_Sum tree/Path_Sum.cpp)
#add_executable(Path_Sum_III tree/Path_Sum_III.cpp)
#add_executable(Subtree_of_Another_Tree tree/Subtree_of_Another_Tree.cpp)
#add_executable(Sum_of_Left_Leaves tree/Sum_of_Left_Leaves.cpp)
#add_executable(Longest_Univalue_Path tree/Longest_Univalue_Path.cpp)
#add_executable(House_Robber_III tree/House_Robber_III.cpp util/BinTree.cpp)
#add_executable(Implement_Trie tree/Implement_Trie.cpp)
#add_executable(Map_Sum_Pairs tree/Map_Sum_Pairs.cpp)
#add_executable(Build_Bin_Tree_From_Iterator sword_offer/Build_Bin_Tree_From_Iterator.cpp)
#add_executable(Next_Node_In_Bin_Tree sword_offer/Next_Node_In_Bin_Tree.cpp)
#add_executable(Fibonacci sword_offer/Fibonacci.cpp)
add_executable(Full_Tree_Is_BinSearch_Tree tree/Full_Tree_Is_BinSearch_Tree.cpp)

# design
#add_executable(SingleInstance design/SingleInstance.cpp)
#add_executable(SimpleFactory design/SimpleFactory.cpp)
#add_executable(FactoryMethod design/FactoryMethod.cpp)
#add_executable(AbstractFactory design/AbstractFactory.cpp)
#add_executable(ThreadPool design/ThreadPool.cpp)
#add_executable(LRU_Cache design/LRU_Cache.cpp)
#add_executable(LFU_Cache design/LFU_Cache.cpp)

# stack_and_queue
#add_executable(Implement_Queue_using_Stacks stack_and_queue/Implement_Queue_using_Stacks.cpp)
#add_executable(Implement_Stack_using_Queues stack_and_queue/Implement_Stack_using_Queues.cpp)
#add_executable(Min_Stack stack_and_queue/Min_Stack.cpp)
#add_executable(Valid_Parentheses stack_and_queue/Valid_Parentheses.cpp)
#add_executable(Daily_Temperatures stack_and_queue/Daily_Temperatures.cpp)
#add_executable(Next_Greater_Element_II stack_and_queue/Next_Greater_Element_II.cpp)
#add_executable(Duplicate_Number_In_Array sword_offer/Duplicate_Number_In_Array.cpp)

# partion
#add_executable(Different_Ways_to_Add_Parentheses partion/Different_Ways_to_Add_Parentheses.cpp)

# bit_manipulation
#add_executable(Two_Unduplicate_Numbers_in_Array bit_manipulation/Two_Unduplicate_Numbers_in_Array.cpp)
#add_executable(Number_Of_1 bit_manipulation/Number_Of_1.cpp)

# exam
#add_executable(360_Test_IO exam/360_Test_IO.cpp)

# other
#add_executable(Max_Kuohao_Match other/Max_Kuohao_Match.cpp)
#add_executable(Move_Zero_To_Tail other/Move_Zero_To_Tail.cpp)
#add_executable(maxDiffSubArrays other/maxDiffSubArrays.cpp)
#add_executable(Reverse_Sentence matrix/Reverse_Sentence.cpp)
#add_executable(Robot_Move sword_offer/Robot_Move.cpp)