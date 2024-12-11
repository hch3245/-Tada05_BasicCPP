// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collision/CBoxBase.h"
#include "CSphereTrace_Trigger.generated.h"

/**
 * 
 */
UCLASS()
class BASICCPP_API ACSphereTrace_Trigger : public ACBoxBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
