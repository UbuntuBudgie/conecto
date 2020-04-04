/* devices-list.h
 *
 * Copyright 2020 Hannes Schulze <haschu0103@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

#include <gtkmm.h>
#include "../models/connected-devices.h"
#include "../models/unavailable-devices.h"
#include "../models/available-devices.h"

namespace App {
namespace Views {

/**
 * @brief A list shown on the left-hand side of the main window
 * 
 * A list shown in the main window, listing all online, offline and available devices
 * 
 * Connected to the following models: @p App::Models::ConnectedDevices, @p App::Models::UnavailableDevices,
 * @p App::Models::AvailableDevices
 */
class DevicesList : public Gtk::Box {
  public:
    /**
     * @brief Create a list of devices, visualizing the specified models
     * 
     * @param connected_devices The connected-devices model
     * @param unavailable_devices The unavailable-devices model
     * @param available_devices The available-devices model
     */
    DevicesList (const Glib::RefPtr<Models::ConnectedDevices>& connected_devices,
                 const Glib::RefPtr<Models::UnavailableDevices>& unavailable_devices,
                 const Glib::RefPtr<Models::AvailableDevices>& available_devices);
    ~DevicesList () {}

    DevicesList (const DevicesList&) = delete;
    DevicesList& operator= (const DevicesList&) = delete;

  private:
    Glib::RefPtr<Models::ConnectedDevices> m_connected_devices;
    Glib::RefPtr<Models::UnavailableDevices> m_unavailable_devices;
    Glib::RefPtr<Models::AvailableDevices> m_available_devices;

    Gtk::TreeView m_connected_view;
    Gtk::TreeView m_unavailable_view;
    Gtk::TreeView m_available_view;
};

} // namespace Views
} // namespace App