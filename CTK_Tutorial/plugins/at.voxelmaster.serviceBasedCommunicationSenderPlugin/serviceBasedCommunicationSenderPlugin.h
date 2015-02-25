/*=============================================================================

  Library: CTK

  Copyright (c) <voxelmaster/ 4D-Visualization, Univ. ENT Clinic, Innsbruck Medical University>

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/



#ifndef serviceBasedCommunicationSenderPlugin_H
#define serviceBasedCommunicationSenderPlugin_H

#include "serviceInterface.h"

#include <ctkPluginActivator.h>
#include <service/event/ctkEventConstants.h>
#include <service/event/ctkEventAdmin.h>
#include <service/event/ctkEvent.h>

#include <QString>
#include <QLibrary>




class serviceBasedCommunicationSenderPlugin :  public QObject, public ctkPluginActivator
{
	Q_OBJECT
    Q_PLUGIN_METADATA(IID "at.voxelmaster.serviceBasedCommunicationSenderPlugin")
	Q_INTERFACES(ctkPluginActivator)



public:

	serviceBasedCommunicationSenderPlugin();
	~serviceBasedCommunicationSenderPlugin();

	void start(ctkPluginContext* context);
	void stop(ctkPluginContext* context);

	static serviceBasedCommunicationSenderPlugin* getInstance();

	ctkPluginContext* getPluginContext() const;

	void sendServiceToReceiver();

private:

	static serviceBasedCommunicationSenderPlugin* instance;
	ctkPluginContext* context;


	serviceInterface			*interfaceInstance;
	ctkServiceRegistration 		serviceRegistrationReference;


}; // serviceBasedCommunicationSenderPlugin

#endif // serviceBasedCommunicationSenderPlugin_H