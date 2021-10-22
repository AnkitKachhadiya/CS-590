for m in 2500 5000 7500 10000  
do 
    for n in 25 35 45
    do 
        echo $'\n\n'"m n Runtime_for_ris" &>> output21.txt
        for i in {1..5}
        do
            ./hw2 $m $n 0 &>> output21.txt
        done
    done
done

# for m in 50000 100000 500000 750000 
# do 
#     for n in 25 35 45
#     do 
#         echo $'\n\n'"m n Runtime_for_rcs" &>> output11.txt
#         for i in {1..5}
#         do
#             ./hw2 $m $n 1 &>> output11.txt
#         done
#     done
# done