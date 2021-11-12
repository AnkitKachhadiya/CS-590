# for n in 50000 65000 80000 95000 110000 125000
# do 
#     for order in -1 0 1
#     do 
#         echo $'\n\n'"Sample_Type n Runtime_for_rb" &>> output1.txt
#         for i in {1..7}
#         do
#             ./hw3 $n $order 1 &>> output1.txt
#         done
#     done
# done

# for n in 50000 65000 80000 95000 110000 125000
# do 
#     for order in -1 0 1
#     do 
#         echo $'\n\n'"Sample_Type n Runtime_for_bs" &>> output2.txt
#         for i in {1..7}
#         do
#             ./hw3 $n $order 0 &>> output2.txt
#         done
#     done
# done

for n in 50000 65000 80000 95000 110000 125000
do 
    for order in 1
    do 
        # echo $'\n\n'"Sample_Type n Runtime_for_bs $n" &>> output4.txt
        # for i in {1..7}
        # do
            ./hw3 $n $order 1 &>> output4.txt
        # done
    done
done