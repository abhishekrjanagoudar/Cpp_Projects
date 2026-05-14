/*!
 * \file HeatController.cpp
 * \brief Implementation file for the HeatController class.
 *
 * \author AbhisheK_Janagoudar_1134273
 * \date 19-Nov-2024
 */
 */
HeatController::HeatController()
 * \brief Destructor for the HeatController class.
 *
 * Cleans up any resources used by the HeatController. Currently, no additional
 * cleanup is required.
 */
 * \brief Sets the desired room temperature.
 *
    // No dynamic memory is owned here.
 * This method adjusts the room temperature as set by the user.
 * It updates both the user interface and the internal controller with the
// Updates the user-facing value and the stored target.
    // The controller keeps the shared target temperature.
    controller.setTempSetByUser(temp);
}
