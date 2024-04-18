import cv2

def main():
    image = cv2.imread("../resources/test.png")

    if image is None:
        print("Error: couldn't open image")
        exit()

    # OG
    cv2.imshow("original photo", image)
    cv2.waitKey(0)

    # RGB
    rgb_img = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    cv2.imshow("RGB photo", rgb_img) 
    cv2.imwrite("rgb.png", rgb_img) 
    cv2.waitKey(0) 

    # HSV
    hsv_img = cv2.cvtColor(image, cv2.COLOR_RGB2HSV) 

    cv2.imshow("HSV photo", hsv_img) 
    cv2.imwrite("hsv.png", hsv_img) 
    cv2.waitKey(0) 

    # LAB
    lab_img = cv2.cvtColor(image, cv2.COLOR_RGB2Lab) 

    cv2.imshow("LAB photo", lab_img) 
    cv2.imwrite("lab.png", lab_img) 
    cv2.waitKey(0) 

    # grayscale
    gray_img = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY) 

    cv2.imshow("GRAY photo", gray_img) 
    cv2.imwrite("gray.png", gray_img) 
    cv2.waitKey(0) 

    # blur
    blur_img = cv2.GaussianBlur(image, (7, 7), 0) 

    cv2.imshow("Blured photo", blur_img) 
    cv2.imwrite("blur.png", blur_img) 
    cv2.waitKey(0) 

    # sharp
    sharp_img = cv2.Laplacian(blur_img, cv2.CV_16S) 
    sharp_img = cv2.convertScaleAbs(sharp_img) 
    sharp_img = sharp_img + blur_img 

    cv2.imshow("Sharp photo", sharp_img) 
    cv2.imwrite("sharp.png", sharp_img) 
    cv2.waitKey(0) 

    # median
    image = cv2.imread("../resources/noisy.png") 
    cv2.imshow("Noisy image", image) 
    cv2.waitKey(0) 

    median_img = cv2.medianBlur(image, 3) 

    cv2.imshow("Median photo", median_img) 
    cv2.imwrite("median.png", median_img) 
    cv2.waitKey(0) 

    cv2.destroyAllWindows() 


if __name__ == "__main__":
    main()

