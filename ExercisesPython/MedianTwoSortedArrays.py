def findMedianSortedArrays(nums1, nums2):
    merge = []
    longitud = max(len(nums1),len(nums2))
    #Encuentra la media pero el array resultante no necesariamente esta organizado
    for i in range(longitud):
        try:
            if nums1[i] > nums2[i]:
                merge.append(nums2[i])
                merge.append(nums1[i])
            else:
                merge.append(nums1[i])
                merge.append(nums2[i])
        except IndexError:
            # Si entramos aquí, es porque nums1[i] o nums2[i] no existe
            try:
                # Intentamos ver si el elemento que existe es el de nums1
                merge.append(nums1[i])
            except IndexError:
                # Si nums1 también falló, por descarte el elemento está en nums2
                merge.append(nums2[i])
    longitud2 = len(merge)
    print(merge)
    if longitud2 % 2 == 0:
        return (merge[(longitud2 // 2) - 1] + merge[(longitud2 // 2)]) / 2
    else:
        return merge[longitud2 // 2]

if __name__ == "__main__":
    nums1 = [1,2,2]
    nums2 = [3,4]
    print(findMedianSortedArrays(nums1, nums2))