  
Robotics Stanford Augmented Cane  
  
brief summary of Stanford research paper -   
Multimodal sensing and intuitive steering assistance improve navigation and mobility for people with impaired vision   
  https://github.com/kwankunghkg/Robotics/blob/main/AugmentedCane/doc/summary.txt  
  
  
Stanford Researchers Build $400 Self-Navigating Smart Cane  
https://hai.stanford.edu/news/stanford-researchers-build-400-self-navigating-smart-cane  
  
Stanford's Smart Cane Helps Visually Impaired Individuals Navigate Better  
The augmented cane can help users detect and identify obstacles, move easily around those objects, and follow routes both indoors and out. Cabe Atwell  
https://www.hackster.io/news/stanford-s-smart-cane-helps-visually-impaired-individuals-navigate-better-e6b1ae4b7132  
  
Multimodal sensing and intuitive steering assistance improve navigation and mobility for people with impaired vision  
Authors : Patrick Slade / Arjun Tambe / Mykel J. Kochenderfer  
Science Robotics • 13 Oct 2021 • Vol 6, Issue 59 •  
https://www.science.org/doi/10.1126/scirobotics.abg6594  
  
  
  
Multiple sclerosis (MS) 多發性硬化症  
  https://en.wikipedia.org/wiki/Multiple_sclerosis  
  
    
-------------------------  
page 6.  
  
Previous electronic travel aids decreased walking speed when compared with a white cane, possibly due to vibrotactile feedback, which could require higher cognitive load than no feedback.   
  
Novice participants reported lower mental demand using the Augmented Cane.  
Third, the Augmented Cane reduced the participants’ number of contacts with the environment in all experiments.   
  
Fourth, there was a correlation between the difference in walking speed and confidence when participants used either the Augmented Cane or white cane. People with impaired vision prefer to use their white cane when learning to use an electronic travel aid because it increases their confidence (38). This may explain why a previous electronic travel aid without a white cane reduced the walking speed compared with a white cane (25). Using a white cane as the base of the Augmented Cane may have increased their confidence and walking speed.  
  
not all participants benefited (table S3 and S4). Additional work could investigate  
  
-------------------------  
page 7  
  
accuracy of the pretrained object classification models depends on lighting (43) and orientation of the object. For example, rotating a stop sign by 60° substantially reduced classification accuracy (Fig. 7A).  
  
found that the Augmented Cane had a lower usability due to the additional weight of the sensors. ... Most expert participants noted that the Augmented Cane was too heavy (table S9), which may explain why the survey reported it as more cumbersome and physically demanding. Thus, weight and complexity are important factors to consider when designing electronic travel aids.  
  
Although the design of the Augmented Cane is open-source, it requires mechanical assembly and soldering, which are challenging for people with impaired vision.   
  
-------------------------  
page 8  
  
Cane did not include specific sensors to detect vertical drops in terrain or head-level obstacles because previous electronic travel aids addressed those concerns with a single ultrasonic sensor (26, 24), which could be easily integrated into the Augmented Cane. Replacing the sensors and microcontroller with a smartphone could simplify the assembly and reduce weight.   
  
-------------------------  
page 10  
  
Design of the Augmented Cane  
  
The Augmented Cane consists of lightweight, portable, and lowcost components that include a set of sensors, microcontroller, and hardware for providing grounded kinesthetic feedback. The total cost of the components is about $400 USD, and the parts list and design is available in a public repository (53). A 2D LIDAR (RPLIDAR-A1, Slamtec) provides rapid distance measurements around the user in the transverse plane. The LIDAR measures 360° with 0.9° between beams and samples the full revolution of measurements at a frequency of 5 Hz. A monocular camera (Camera Module V2, Raspberry Pi Foundation) provides high-resolution images. A GPS breakout board (Ultimate GPS Breakout, Adafruit) and an antenna provide position estimates with an accuracy of 3 m at 1 Hz. An inertial measurement unit, consisting of a three-axis gyroscope, accelerometer, and magnetometer, measures the relative orientation of the Augmented Cane (Precision NXP 9-DOF Breakout Board, Adafruit). A portable microcontroller (Raspberry Pi 4 Model B, Raspberry Pi Foundation) provides computation to perform sensing and feedback in real time. A motorized omni wheel applies torques to steer the user to the left or right while allowing the user to control their forward walking speed (Nexus Robot). The omni wheel provides effective grounded kinesthetic feedback when the Augmented Cane is held at an angle between 20° and 70° to assist participants with different heights. A brushed motor with a low gear ratio of 4.4 to 1 drives the omni wheel, allowing the user to overpower the motor if necessary while providing a peak torque of 0.078 N·m to turn the user up to 90°/s (Pololu). This motor also assisted in sweeping the cane back and forth at a frequency of 1.2 Hz to reduce the effort required by the user during normal operation. A rechargeable battery powered the microcontroller for up to 4.2 hours when using all sensors. A lithium polymer battery powered the motor for 5.2 hours on a single charge. A push button on the handle of the Augmented Cane enabled the participant to turn off the motor.   
  
The code used to control the Augmented Cane and feedback modes during the experiments is available in the open-source Augmented Cane repository (53).  
	53. Public repository for the Augmented Cane materials to be made available upon acceptance.  
  
novice participants were young and healthy with an average age of 25.3 ± 2.8 years. The expert participants had an average age of 45.8 ± 16.1 years and had an average of 17.7 ± 10.8 years of experience using a white cane.   
  
Several mobility metrics were collected to compare navigation with the Augmented Cane and white cane for each trial: distance, duration, average walking speeds, and number of contacts with the environment. Distances during the indoor experiments were computed either with an optical motion capture system (OptiTrack) that measured the positions of a set of five markers on a hat and a set of three or four markers placed on the white cane or Augmented Cane at 100 Hz or by integrating inertial measurements using a zerovelocity update (57) at 100 Hz. Preliminary tests found that the difference in distance estimates using optical motion capture and inertial measurements was less than 4%. Outdoor experiments used GPS positions to compute distance. The average walking speed was computed by dividing the total length of the course by the time the participant took to complete the course. The number of contacts with the environment was counted as any individual strike or slide of the cane along a portion of the environment other than the floor. The metabolic energy expended, while walking was estimated with a mobile K5 respirometry unit (COSMED) that measured oxygen and carbon dioxide.   
  
Comparison of haptic feedback modes   
  
We compared the accuracy of grounded kinesthetic, vibrotactile, and audio feedback in allowing users to accomplish a turn-in-place task. This experiment used a white cane attached to a vertical rod with a connecting bracket that allowed the cane to be held in a comfortable position and rotated in place (fig. S6). A potentiometer mounted at the top of the rod measured the angle as the participant turned in place to an accuracy of 0.1° at a rate of 100 Hz. The experiment consisted of a blindfolded participant turning to the left or right to reach a randomized target angle while receiving feedback. Once the participant thought they reached the target angle, they pressed the push button on the cane handle, returned to their initial position, and pressed the button to receive the prompt for the next  target angle. For each feedback mode, participants received 5 random target angles for practice and then completed 18 target angles, ranging from 90° left to 90° right at increments of 10°. Participants were instructed to reach the target angle as accurately and quickly as possible. Expert white cane users do not regularly receive any of these modes of feedback, so we assumed that the novices and experts would perform similarly and selected novices to complete the experiment.  
  
The feedback modes provided information to the user to help them reach the target angle. Earbuds provided audio feedback to relay verbal instructions to “Turn X degrees to the left (or right),” for a target angle of X degrees. Heading angles were recorded starting immediately after the verbal instructions finished. The motorized omni wheel on the Augmented Cane provided grounded kinesthetic feedback by turning the tip of the cane. Hardware details are included in the previous section on the design of the Augmented Cane. The grounded kinesthetic feedback used a proportional controller, where the torque applied by the motorized omni wheel was linearly related to the error between the current and target angle. The vibrotactile feedback used two vibrating coin motors (Precision Microdrives) placed on the back of the hand holding the cane at the distal index and small metacarpal bones on the hand and driven with a breakout board (DRV2605L, Adafruit). A proportional controller linearly mapped the error between the current and target angles to vibrations in the left or right vibrating motor, similar to previous electronic travel aids that provided vibrotactile feedback (25).  
  
-------------------------  
page 11  
  
Indoor and outdoor navigation experiments  
  
The motion of the participant was recorded with motion capture while simultaneously measuring the metabolic energy expended with respirometry. The cost of transport was computed as the metabolic energy consumed per unit distance.  
  
The Augmented Cane used a proportional controller to provide grounded kinesthetic feedback to steer the user toward the next waypoint, using a GPS waypoint tracking algorithm (fig. S2). If the obstacle avoidance algorithm detected an obstacle, the Augmented Cane played an audio file saying “obstacle ahead” through an earbud. The white cane provided audio feedback every 10 s telling the participant to turn left or right the appropriate number of degrees toward the next waypoint. The current heading of the participant was computed with a magnetometer, and the heading to the next waypoint was computed using the direction from the current GPS location to the waypoint.   
  
The Augmented Cane performed a visual servoing to steer the participant toward a stop sign. The visual servoing algorithm (Fig. 7B) operated at a rate of 1.4 Hz. A pretrained computer vision model, YoloV3Tiny (43), classified the stop sign and any other objects detected in pictures taken by the camera mounted on the Augmented Cane. YoloV3Tiny is a real-time object detection model that uses a deep convolutional neural network to rapidly find multiple objects in an image from a set of 80 object classes (43). The distance to the stop sign was estimated using a linear regression model based on the width and height of the bounding box that detected a stop sign in an image. This linear regression model was trained from stop sign training images consisting of five images taken at each combination of a set of distances (2.5, 5, 7.5, and 10 m) and angles (0°, 30°, and 60° from directly facing the sign) (Fig. 7A). The stop sign’s center pixel location detected by YoloV3Tiny was linearly related to the horizontal camera field of view of 62.2° to find the angle to steer the participant toward the stop sign. The stop sign was selected as a representative object from signs and key objects that are important for wayfinding. One blindfolded novice participant walked toward a stop sign placed 7 m away in an unobstructed indoor environment. The stop sign was rotated 0°, 30°, and 60° from directly facing the person, and the experiment was conducted five times for each angle. The person started at a randomized initial heading angle between 30° to the left or right to ensure the stop sign would be within the camera’s field of view.  
  
-------------------------  
page   
  
  
-------------------------  
  
Movie 1. Summary of the Augmented Cane.  
  https://bcove.video/3Dn8Grd  
  
Movie 2. Comparison of the Augmented Cane and a white cane during indoor experiments.  
  https://bcove.video/3mEH6iD  
  
Movie 3. Comparison of the Augmented Cane and a white cane during an outdoor experiment.  
  https://bcove.video/3luLykN  
  
Movie 4. Demonstration of the Augmented Cane performing closed-loop planning to navigate to a desired indoor position in a cluttered environment.  
  https://bcove.video/3iJo6Oy  
  
Movie 5. Demonstration of the Augmented Cane visual servoing to navigate to a stop sign.  
  https://bcove.video/3uVxbZJ  
  
-------------------------  
  
Movie 1. Summary of the Augmented Cane.  
  https://bcove.video/3Dn8Grd  
The Augmented Cane uses a multimodal set of sensors to perceive the environment and provides grounded kinesthetic feedback to steer the participant. A series of experiments evaluated how novice and expert participants navigated when using the Augmented Cane or a white cane.  
  
Movie 2. Comparison of the Augmented Cane and a white cane during indoor experiments.  
  https://bcove.video/3mEH6iD  
Example trials compare how a representative novice participant navigates with the Augmented Cane and a white cane during a hallway experiment and an obstacle avoidance experiment.  
  
Movie 3. Comparison of the Augmented Cane and a white cane during an outdoor experiment.  
  https://bcove.video/3luLykN  
A time lapse of a novice participant navigating an outdoor asphalt path with the Augmented Cane and a white cane with audio feedback.  
  
Movie 4. Demonstration of the Augmented Cane performing closed-loop planning to navigate to a desired indoor position in a cluttered environment.  
  https://bcove.video/3iJo6Oy  
The Augmented Cane used LIDAR-based SLAM to determine the position of the participant and the environment. This map was then filtered to detect obstacles, and a path planning algorithm, A*, computed a trajectory to safely reach the desired position. The grounded kinesthetic feedback then steered the user along this trajectory.  
  
Movie 5. Demonstration of the Augmented Cane visual servoing to navigate to a stop sign.  
  https://bcove.video/3uVxbZJ  
The visual servoing algorithm consists of taking an image, classifying the stop sign with a bounding box, computing the angle to turn toward the stop sign, estimating the distance to the stop sign using the height and width of the bounding box, and then using the motor to steer the Augmented Cane.  
  
-------------------------  
  
  
// Assistive robots have the potential to support people with disabilities in a variety of activities of daily living, such as dressing.  //  
  
Learning garment manipulation policies toward robot-assisted dressing  
https://www.science.org/doi/10.1126/scirobotics.abm6010  
  
  
  
-------------------------  
end of file  
