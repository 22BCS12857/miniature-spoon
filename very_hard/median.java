package very_hard;

import java.util.List;
import java.util.ArrayList;

public class median {
    public double findMedianSortedArrays(List<Integer> a, List<Integer> b) {
        int aIndex = 0;
        int bIndex = 0;
        List<Integer> medianList = new ArrayList<>();

        // Traverse through both lists
        for (int i = 0; i <= (a.size() + b.size()) / 2; i++) {
            if (aIndex >= a.size()) {
                medianList.add(b.get(bIndex));
                bIndex++;
            } else if (bIndex >= b.size()) {
                medianList.add(a.get(aIndex));
                aIndex++;
            } else {
                if (a.get(aIndex) <= b.get(bIndex)) {
                    medianList.add(a.get(aIndex));
                    aIndex++;
                } else {
                    medianList.add(b.get(bIndex));
                    bIndex++;
                }
            }
        }

        // Calculate the median based on the combined list size
        if ((a.size() + b.size()) % 2 == 0) {
            return (medianList.get(medianList.size() - 1) + medianList.get(medianList.size() - 2)) / 2.0;
        } else {
            return medianList.get(medianList.size() - 1);
        }
    }

    public static void main(String[] args) {
        // Case 1
        median s = new median();

        List<Integer> a = new ArrayList<>();
        a.add(1);
        a.add(3);

        List<Integer> b = new ArrayList<>();
        b.add(2);

        double median = s.findMedianSortedArrays(a, b);
        System.out.println("Median: " + median);//Expected: 2
        //Case 2

        List<Integer> a_0 = new ArrayList<>();
        a_0.add(1);
        a_0.add(2);

        List<Integer> b_0 = new ArrayList<>();
        b_0.add(3);
        b_0.add(4);

        double median_0 = s.findMedianSortedArrays(a_0, b_0);
        System.out.println("Median: " + median_0);//Expected: 2.5
    }
}
