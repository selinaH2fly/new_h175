import cv2
import os
import argparse


# Main function
def make_video(experiment_folder, test=True):

    # Change the current working directory to the experiment folder
    os.chdir(experiment_folder)

    # Set the path to the folder containing your PNG frames and the output video file name
    frame_folder = os.getcwd()

    if test:
        output_video = "model_performance_test_video.avi"
    else:
        output_video = "model_performance_train_video.avi"

    # Define the frame rate and frame size
    frame_rate = 5  # Adjust as needed

    # Get a list of the PNG files in the folder
    if test:
        frame_files = sorted([f for f in os.listdir(frame_folder) if f.startswith("model_performance_test")], key=lambda x: int(''.join(filter(str.isdigit, os.path.splitext(x)[0]))))
    else:
        frame_files = sorted([f for f in os.listdir(frame_folder) if f.startswith("model_performance_train")], key=lambda x: int(''.join(filter(str.isdigit, os.path.splitext(x)[0]))))


    # Extract frame size from first frame
    frame_path = os.path.join(frame_folder, frame_files[0])
    frame = cv2.imread(frame_path)
    height, width, _ = frame.shape

    # Initialize VideoWriter
    fourcc = 0
    out = cv2.VideoWriter(output_video, fourcc, frame_rate, (width, height))

    # Loop through the PNG frames and add them to the video
    for frame_file in frame_files:
        frame_path = os.path.join(frame_folder, frame_file)
        frame = cv2.imread(frame_path)
        out.write(frame)

    # Release the VideoWriter
    out.release()

    return None

print("Video creation complete.")

# Entry point of the script
if __name__ == '__main__':

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Make a video from model performance snapshots")
    parser.add_argument("-d", "--dir", type=str, help="Experiment subfolder containing PNG files")
    parser.add_argument("-t", "--test", type=int, help="Make video from test data (1) or training data (0)", default=True)

    args = parser.parse_args()

    # Call the main function                        
    make_video(args.dir, args.test)
