for m in 100000 250000
do 
    for n in 10 25 50
    do 
        for order in 0 -1
        do 
            # echo 'm = '$m 'n = '$n 'order = ' $order &>> output.txt
            echo $'\n\n'"Runtime_${m}_${n}_${order}" &>> output4.txt
            for i in 1
            do 
                ./hw1 $m $n 0 $order &>> output4.txt
            done
        done
    done
done

# for m in 1000 2500 
# do 
#     for n in 10 
#     do 
#         for order in 0 1 -1
#         do 
#             # echo 'm = '$m 'n = '$n 'order = ' $order &>> output.txt
#             echo $'\n\n'"Runtime_${m}_${n}_${order}" &>> output2.txt
#             for i in {1..5}
#             do 
#                 ./hw1 $m $n 1 $order &>> output2.txt
#             done
#         done
#     done
# done