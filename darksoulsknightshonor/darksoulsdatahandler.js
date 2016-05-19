//data variable name: items. Two keys: item and description

var app = angular.module("darksoulschecklist", []);

app.controller("checklistcontroller", function($scope){
	
	//$scope.info = "";
	
	function storageExists()
	{
		if(typeof(Storage) === "undefined")
			return false;
		
		return true;
	}
	
	//Function name: isChecked
	//Purpose: to check if the item exists in local storage, if it does not, add it and return a boolean representing if we have a checked item.
	//Accepts: an item name
	//Returns: a boolean
	
	$scope.isChecked = function(item)
	{
		if(!storageExists())
			return false;
		
		var state = localStorage.getItem(item);
		
		if(state === null)
		{
			localStorage.setItem(item, "false");
			return false;
		}
		
		if(state == "false")
			return false;
		
		return true;
	}
	
	//Function name: changeKey
	//Purpose: To change the value of the key in local storage.
	//Accepts: a key value.
	//Returns: nothing.
	
	$scope.changeKey = function(item)
	{
		if(storageExists())
		{
			var state = localStorage.getItem(item);
			
			if(state !== null)
			{
				if(state == "false")
					localStorage.setItem(item, "true");
				else
					localStorage.setItem(item, "false");
			}
		}
	}
	
	$scope.items = items;
	
	$scope.changeInfo = function(info, name)
	{
		$("#modalHeader").text(name);
		$("#info").val(info);
	}
	
});