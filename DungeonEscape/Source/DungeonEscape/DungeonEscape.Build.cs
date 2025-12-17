// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DungeonEscape : ModuleRules
{
	public DungeonEscape(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"DungeonEscape",
			"DungeonEscape/Variant_Horror",
			"DungeonEscape/Variant_Horror/UI",
			"DungeonEscape/Variant_Shooter",
			"DungeonEscape/Variant_Shooter/AI",
			"DungeonEscape/Variant_Shooter/UI",
			"DungeonEscape/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
