

			//newHashString = currentHashString;
			//newHashString += "-" + shipAndIndex.first.getWidth();
			//newHashString += "-" + shipAndIndex.first.getHeight();
			//newHashString += "-" + std::to_string(currentMatrixPos);

			//size_t hashedValue = getHash(newHashString);
			//bool isCached = lookupCache.find(hashedValue) != lookupCache.end();

			//if (isCached) {
			//	CacheData cacheData = lookupCache.at(hashedValue);
			//	if (cacheData.canPlace) {
			//		nextGridNodeState = cacheData.grid;

			//		numOfLeaves += dfs(false, matrisPos, col, row, numOfUniqueShips, gridSideSize, shipAndIndex.second, newHashString,
			//			lookupCache, allShipsToTest, cacheData.grid, placedShips);
			//	}
			//}
			//else {
			//	CacheData cacheData;
			//	nextGridNodeState = nodeGridState;

			//	if (tryPlaceShip(col, row, gridSideSize, nextGridNodeState, shipAndIndex.first))
			//	{
			//		cacheData.grid = nextGridNodeState;
			//		cacheData.canPlace = true;

			//		lookupCache[hashedValue] = cacheData;

			//		numOfLeaves += dfs(false, matrisPos, col, row, numOfUniqueShips, gridSideSize, shipAndIndex.second, newHashString,
			//			lookupCache, allShipsToTest, nextGridNodeState, placedShips);
			//	}
			//	else {
			//		cacheData.canPlace = false;
			//		lookupCache[hashedValue] = cacheData;
			//	}
			//}