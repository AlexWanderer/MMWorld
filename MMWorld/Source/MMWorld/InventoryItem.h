// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractivebleActor.h"
#include "InventoryItem.generated.h"

UCLASS()
class MMWORLD_API AInventoryItem : public AInteractivebleActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryItem();

	void EnterInventory(class AMMWorldCharacter* NewOwningPawn);
	void LeaveInventory(class AMMWorldCharacter* NewOwningPawn);

	virtual void OnEnterInventory(class AMMWorldCharacter* NewOwningPawn) {}
	virtual void OnLeaveInventory(class AMMWorldCharacter* NewOwningPawn) {}

	bool IsInInventory() const { return bInInventory; }
	bool CanBeEquiped() const { return bCanBeEquiped; }

	const FString& GetItemName() const { return ItemName; }

	virtual FTransform GetHandBindPointTransform() const;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void OnStartPrimaryAction() {}
	virtual void OnStopPrimaryAction() {}
	virtual void OnStartSecondaryAction() {}
	virtual void OnStopSecondaryAction() {}

	virtual void OnStartUse_Implementation();

	void Equip();
	void Unequip();

	virtual void OnEquip() {}
	virtual void OnUnequip() {}

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString ItemName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* PickupTrigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	uint32 bCanBeEquiped : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	uint32 bInInventory : 1;
};
